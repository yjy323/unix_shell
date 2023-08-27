/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_filesystem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:15:19 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:57:02 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "minishell.h"
#include "prompt.h"
#include "execute.h"
#include "status.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "utils.h"

int			execute_filesystem(t_word_list *words, char *curr_cmd);
static void	execute_filesystem_internal(t_word_list *words, char *curr_cmd,
				t_environment *environ);
static char	**make_argument(t_word_list *words);
static char	*set_excutable_file(char *file, t_hash_table *table);
static char	*search_excutable_file(char *file, char **path);

int	execute_filesystem(t_word_list *words, char *curr_cmd)
{
	int			pid;
	int			status;

	status = g_sh_variable.status;
	pid = fork();
	if (pid == -1)
		return (exception_handler(EGENRAL, curr_cmd, 0, 0));
	else if (pid == 0)
		execute_filesystem_internal(words, curr_cmd, g_sh_variable.environment);
	else
		status = job_control(pid);
	return (status);
}

static void	execute_filesystem_internal(t_word_list *words, char *curr_cmd,
				t_environment *environ)
{
	char	**argument;
	char	*executable_file;
	char	*file;

	initialize_shell_signals(2);
	file = curr_cmd;
	argument = make_argument(words);
	executable_file = set_excutable_file(file, environ->env_table);
	if (access(executable_file, F_OK) != 0)
		exception_handler_sub_ps(ENOCMD, curr_cmd, 0, MNOCMD);
	else if (access(executable_file, X_OK) != 0)
		exception_handler_sub_ps(ENOPERM, curr_cmd, 0, 0);
	else if (execve(executable_file, argument, environ->env_array) == -1)
		exception_handler_sub_ps(EGENRAL, curr_cmd, 0, 0);
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
	argument = xmalloc(sizeof(char *) * (cnt + 1));
	argument[cnt] = 0;
	i = 0;
	while (i < cnt)
	{
		argument[i] = ft_xstrdup(words->word->word);
		i++;
		words = words->next;
	}
	return (argument);
}

static char	*set_excutable_file(char *file, t_hash_table *table)
{
	char	*executable_file;
	char	**path;
	char	*env_path;

	executable_file = 0;
	if (access(file, F_OK | X_OK) == 0)
		return (file);
	env_path = hash_search_variable_value("PATH", table);
	if (env_path)
	{
		path = ft_split(env_path, ':');
		executable_file = search_excutable_file(ft_xstrjoin("/", file), path);
	}
	if (!executable_file)
		return (file);
	else
		return (executable_file);
}

static char	*search_excutable_file(char *file, char **path)
{
	char	**tmp;
	char	*del;
	char	*temp_executable_file;
	char	*executable_file;

	tmp = path;
	executable_file = 0;
	while (*tmp)
	{
		temp_executable_file = ft_xstrjoin(*tmp, file);
		if (!executable_file && access(temp_executable_file, F_OK) == 0)
			executable_file = temp_executable_file;
		else
			free(temp_executable_file);
		del = *tmp;
		tmp++;
		free(del);
	}
	free(file);
	free(path);
	return (executable_file);
}
