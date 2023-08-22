/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:52:23 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/22 17:40:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "expand/expand.h"

#include "libft.h"

extern int	g_status;

int			execute_simple_command(t_command *command, t_environment *environ, int pipe_in_fd, int pipe_out_fd);
static int	execute_buitin(t_word_list *words, t_environment *environ);
static int	execute_filesystem(t_word_list *words, char **environ);
static char	**make_argument(t_word_list *words);
static char	*search_file(char *file);

int		execute_simple_command(t_command *command, t_environment *environ, int pipe_in_fd, int pipe_out_fd)
{
	int			save_stdin_fd;
	int			save_stdout_fd;
	t_word_list	*tmp;

	if (pipe_in_fd != -1)
		dup2(pipe_in_fd, STDIN_FILENO);
	if (pipe_out_fd != -1)
		dup2(pipe_out_fd, STDOUT_FILENO);
	save_stdin_fd = dup(STDIN_FILENO);
	save_stdout_fd = dup(STDOUT_FILENO);
	do_redirect(command->simple->redirects);
	tmp = command->simple->words;
	command->simple->words = expand_words(command->simple->words);
	free(tmp);
	g_status = execute_buitin(command->simple->words, environ);
	if (g_status == ENOCMD)
		g_status = execute_filesystem(command->simple->words, environ->env_array);
	undo_redirect(save_stdin_fd, save_stdout_fd);
	return (g_status);
}

static int	execute_buitin(t_word_list *words, t_environment *environ)
{
	int			status;
	int			len;
	char		*command;
	t_word_list	*argument;

	command = words->word->word;
	argument = words->next;
	len = ft_strlen(command);
	if (!ft_strncmp(command, "cd", len))
		status = ft_cd(argument, environ);
	else if (!ft_strncmp(command, "echo", len))
		status = ft_echo(argument);
	else if (!ft_strncmp(command, "env", len))
		status = ft_env(argument, environ);
	else if (!ft_strncmp(command, "exit", len))
		status = ft_exit(argument, g_status);
	else if (!ft_strncmp(command, "export", len))
		status = ft_export(argument, environ);
	else if (!ft_strncmp(command, "pwd", len))
		status = ft_pwd();
	else if (!ft_strncmp(command, "unset", len))
		status = ft_unset(argument, environ);
	else
		return (ENOCMD);
	return (status);
}

static int	execute_filesystem(t_word_list *words, char **environ)
{
	char		*exec_path;
	char		**argument;
	int			pid;
	int			status;

	argument = 0;
	status = g_status;
	pid = fork();
	if (pid == -1)
		crash(1, "fork()");
	else if (pid == 0)
	{
		argument = make_argument(words);
		exec_path = search_file(words->word->word);
		if (execve(exec_path, argument, environ) == ERROR)
			crash(1, words->word->word);
	}
	else
	{
		waitpid(pid, &status, 0);
		status = WEXITSTATUS(status);
		if (argument)
		{
			while (*argument)
				free(*(argument++));
			free(argument);
		}
	}
	return (status);
}

static char	**make_argument(t_word_list *words)
{
	char		**argument;
	t_word_list	*iter;
	int			cnt;
	int			i;

	iter = words;
	cnt = 0;
	while (iter)
	{
		iter = iter->next;
		cnt++;
	}
	argument = malloc(sizeof(char *) * (cnt + 1));
	if (!argument)
		crash(1, words->word->word);
	argument[cnt] = 0;
	i = 0;
	while (i < cnt)
	{
		argument[i] = ft_strdup(words->word->word);
		if (!argument[i++])
			crash(1, words->word->word);
		words = words->next;
	}
	return (argument);
}

static char	*search_file(char *file)
{
	char	*rel_path_file;
	char	*exec_file;
	char	**path;
	char	*del;

	if (access(file, F_OK) == 0)
		return (file);
	del = getenv("PATH");
	path = ft_split(del, ':');
	rel_path_file = ft_strjoin("/", file);
	if (!rel_path_file)
		crash(1, file);
	while (*path)
	{
		del = *path;
		exec_file = ft_strjoin(*path++, rel_path_file);
		if (!exec_file)
			crash(1, file);
		else if (access(exec_file, F_OK) == 0)
			break ;
		free(exec_file);
		free(del);
	}
	free(rel_path_file);
	if (access(exec_file, X_OK) != 0)
		crash(126, file);
	return (exec_file);
}
