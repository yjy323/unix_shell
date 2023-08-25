/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:46:22 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 15:34:35 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "expand/expand.h"
#include "parse/lex_list.h"
#include "initialize.h"
#include "variables.h"
#include "utils.h"
#include "status.h"
// ft_xitoa();
#include "libft.h"

int			take_heredoc(t_lex_list *cur, \
						t_sh_variable *sh_variable, int heredoc_num);
static char	*get_heredoc_name(char *wtd, int heredoc_num);
static void	do_heredoc(char *filename, char *limiter, t_environment *environ);

int	take_heredoc(t_lex_list *cur, \
					t_sh_variable *sh_variable, int heredoc_num)
{
	int		pid;
	int		status;
	char	*filename;

	status = 0;
	pid = fork();
	filename = get_heredoc_name(sh_variable->wtd, heredoc_num);
	if (pid == -1)
		return (exception_handler(EGENRAL, "fork()"));
	else if (pid == 0)
	{
		initialize_shell_signals(1);
		do_heredoc(filename, cur->next->data->word, sh_variable->environment);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cur->next->data->word);
		cur->next->data->word = filename;
		status = WEXITSTATUS(status);
	}
	return (status);
}

static char	*get_heredoc_name(char *wtd, int heredoc_num)
{
	char	*res;
	char	*str_num;

	str_num = ft_xitoa(heredoc_num);
	res = ft_xstrjoin(wtd, str_num);
	free(str_num);
	return (res);
}

static void	do_heredoc(char *filename, char *limiter, t_environment *environ)
{
	int		fd;
	char	*line;
	char	*oline;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (rl_eof_found)
			exit(1);
		if (ft_strlen(line) == ft_strlen(limiter)
			&& !ft_strncmp(line, limiter, ft_strlen(line)))
			break ;
		oline = line;
		line = expand_for_heredoc(line, environ);
		free(oline);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
}
