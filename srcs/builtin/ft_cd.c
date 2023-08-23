/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:28:05 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 15:02:40 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"

int			ft_cd(t_word_list *list, t_environment *environ);
static int	set_pwd(t_environment *environ);
static int	set_oldpwd(t_environment *environ);

int	ft_cd(t_word_list *list, t_environment *environ)
{
	char	*dir_name;

	if (list)
		dir_name = list->word->word;
	else
		dir_name = getenv("HOME");
	chdir(dir_name);
	set_oldpwd(environ);
	set_pwd(environ);
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
		hash_remove("OLDPWD", environ->env_table);
		remove_export_env("OLDPWD", environ->env_array);
	}
	return (0);
}
