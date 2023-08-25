/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:46:22 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 20:07:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"
#include "expand/expand.h"
#include "parse/lex_list.h"
#include "initialize.h"
#include "variables.h"
#include "utils.h"
#include "status.h"
#include "libft.h"

int			take_heredoc(t_lex_list *cur, int heredoc_num);
static char	*get_heredoc_name(int heredoc_num);
static void	do_heredoc(char *filename, char *limiter);

int	take_heredoc(t_lex_list *cur, int heredoc_num)
{
	int		pid;
	int		status;
	char	*filename;

	status = 0;
	pid = fork();
	filename = get_heredoc_name(heredoc_num);
	if (pid == -1)
		return (exception_handler(EGENRAL, "fork()"));
	else if (pid == 0)
	{
		initialize_shell_signals(2);
		do_heredoc(filename, cur->next->data->word);
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

static char	*get_heredoc_name(int heredoc_num)
{
	char	*res;
	char	*str_num;

	str_num = ft_xitoa(heredoc_num);
	res = ft_xstrjoin(g_sh_variable.temp_dir_path, str_num);
	free(str_num);
	return (res);
}

static void	do_heredoc(char *filename, char *limiter)
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
		line = expand_for_heredoc(line);
		free(oline);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
}
