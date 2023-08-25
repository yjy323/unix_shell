/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:28:05 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 19:51:02 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>
#include <unistd.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"

int			ft_cd(t_word_list *list);
static int	set_pwd(t_environment *environ);
static int	set_oldpwd(t_environment *environ);

int	ft_cd(t_word_list *list)
{
	char	*dir_name;

	if (list)
		dir_name = list->word->word;
	else
		dir_name = hash_search_variable_value("HOME", g_sh_variable.environment->env_table);
	chdir(dir_name);
	set_oldpwd(g_sh_variable.environment);
	set_pwd(g_sh_variable.environment);
	return (0);
}

static int	set_pwd(t_environment *environ)
{
	char	*value;

	value = getcwd(0, 0);
	bind_variable("PWD", value, environ->env_table, V_NOCREATE);
	update_export_env("PWD", value, environ, V_NOCREATE);
	free(value);
	return (0);
}

static int	set_oldpwd(t_environment *environ)
{
	char				*value;
	t_bucket_contents	*bucket;

	bucket = hash_search("PWD", environ->env_table);
	if (bucket)
	{
		value = ((t_variable *)bucket->data)->value;
		bind_variable("OLDPWD", value, environ->env_table, V_NOCREATE);
		update_export_env("OLDPWD", value, environ, V_NOCREATE);
	}
	else
	{
		bucket = hash_remove("OLDPWD", environ->env_table);
		remove_export_env("OLDPWD", environ->env_array);
		if (bucket)
		{
			if (bucket->key)
				free(bucket->key);
			free(bucket);
		}
	}
	return (0);
}
