/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_filesystem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:15:19 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 15:37:01 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"

#include "libft.h"
#include "utils.h"

int			execute_filesystem(t_word_list *words, t_environment *environ);
static void	execute_filesystem_internal(t_word_list *words,
				t_environment *environ);
static char	**make_argument(t_word_list *words);
static char	*set_excutable_file(char *file, t_hash_table *table);
static char	*search_excutable_file(char *file, char **path);

int	execute_filesystem(t_word_list *words, t_environment *environ)
{
	int			pid;
	int			status;

	status = g_status;
	pid = fork();
	if (pid == -1)
		return (exception_handler(EGENRAL, "fork()"));
	else if (pid == 0)
		execute_filesystem_internal(words, environ);
	else
	{
		waitpid(pid, &status, 0);
		status = WEXITSTATUS(status);
	}
	return (status);
}

static void	execute_filesystem_internal(t_word_list *words,
				t_environment *environ)
{
	char	**argument;
	char	*executable_file;
	char	*file;

	file = words->word->word;
	argument = make_argument(words);
	executable_file = set_excutable_file(file, environ->env_table);
	if (access(executable_file, F_OK) != 0)
		exit (exception_handler(ENOCOMD, file));
	else if (access(executable_file, F_OK) != 0)
		exit (exception_handler(ENOPERM, file));
	else if (execve(executable_file, argument, environ->env_array) == -1)
		exit (exception_handler(EMISUSE, file));
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
	path = ft_split(hash_search_variable_value("PATH", table), ':');
	executable_file = search_excutable_file(ft_xstrjoin("/", file), path);
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
