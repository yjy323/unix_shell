/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_filesystem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:15:19 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 21:24:35 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "initialize.h"
#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"

#include "libft.h"
#include "utils.h"

int	execute_filesystem(t_word_list *words, char *curr_cmd);
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
	{
		waitpid(pid, &status, 0);
		status = WEXITSTATUS(status);
	}
	return (status);
}

static void	execute_filesystem_internal(t_word_list *words, char *curr_cmd,
				t_environment *environ)
{
	char	**argument;
	char	*executable_file;
	char	*file;

	initialize_shell_signals(2);
	file = words->word->word;
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

	if (access(file, F_OK | X_OK) == 0)
		return (file);
	path = ft_split(hash_search_variable_value("PATH", table), ':'); // seg check
	executable_file = search_excutable_file(ft_xstrjoin("/", file), path);
	if (!executable_file)
		return (file);
	else
		return (executable_file);
}

static char	*search_excutable_file(char *file, char **path)
{
	char	**tmp;
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
		free(*tmp);
		tmp++;
	}
	free(file);
	free(path);
	return (executable_file);
}
