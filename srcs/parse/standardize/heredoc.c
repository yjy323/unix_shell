/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:46:22 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/28 13:56:12 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"

#include "minishell.h"
#include "prompt.h"
#include "parse/lex_list.h"
#include "expand/expand.h"
#include "status.h"
#include "variables.h"
#include "utils.h"

int			take_heredoc(t_lex_list *cur, int heredoc_num);
static char	*get_heredoc_name(int heredoc_num);
static void	do_heredoc(char *filename, char *limiter);
static void	heredoc_reader_loop(int fd, char *limiter);

int	take_heredoc(t_lex_list *cur, int heredoc_num)
{
	int		pid;
	int		status;
	char	*filename;

	status = 0;
	pid = fork();
	filename = get_heredoc_name(heredoc_num);
	if (pid == -1)
		return (exception_handler(EGENRAL, "fork()", 0, 0));
	else if (pid == 0)
	{
		initialize_shell_signals(3);
		do_heredoc(filename, cur->next->data->word);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		status = WEXITSTATUS(status);
		free(cur->next->data->word);
		cur->next->data->word = filename;
	}
	return (status);
}

static char	*get_heredoc_name(int heredoc_num)
{
	char	*res;
	char	*temp_filename;
	char	*str_num;

	temp_filename = "_temp_here_doc.tmp";
	str_num = ft_xitoa(heredoc_num);
	temp_filename = ft_xstrjoin(str_num, temp_filename);
	res = ft_xstrjoin(g_sh_variable.temp_dir_path, temp_filename);
	free(temp_filename);
	free(str_num);
	return (res);
}

static void	do_heredoc(char *filename, char *limiter)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	heredoc_reader_loop(fd, limiter);
	close(fd);
}

static void	heredoc_reader_loop(int fd, char *limiter)
{
	char	*line;
	char	*oline;

	while (1)
	{
		line = readline("> ");
		if (rl_eof_found
			|| (ft_strlen(line) == ft_strlen(limiter)
				&& !ft_strncmp(line, limiter, ft_strlen(line))))
			break ;
		oline = line;
		line = expand_for_heredoc(line);
		free(oline);
		write((int)fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
}
