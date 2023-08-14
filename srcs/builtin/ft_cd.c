/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:28:05 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/11 22:29:49 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"

extern char	**environ;

int			ft_cd(t_word_list *list, t_hash_table *table);
static int	setpwd(t_hash_table *table);
static int	setoldpwd(t_hash_table *table);

int	ft_cd(t_word_list *list, t_hash_table *table)
{
	char	*dir_name;
	int		no_free_var;

	no_free_var = 1;
	if (list)
		dir_name = list->word;
	else
	{
		dir_name = getenv("HOME");
		no_free_var = 0;
	}
	chdir(dir_name);
	setoldpwd(table);
	setpwd(table);
	if (!no_free_var)
		free(dir_name);
	return (0);
}

static int	setpwd(t_hash_table *table)
{
	char	*value;

	value = getcwd(0, 0);
	bind_variable("PWD", value, table, V_NOCREATE);
	update_export_env("PWD", value, table, V_NOCREATE);
	free(value);
	return (0);

}

static int	setoldpwd(t_hash_table *table)
{
	char				*value;
	t_bucket_contents	*bucket;

	bucket = hash_search("PWD", table);
	if (bucket)
	{
		value = ((t_variable *)bucket->data)->value;
		bind_variable("OLDPWD", value, table, V_NOCREATE);
		update_export_env("OLDPWD", value, table, V_NOCREATE);
	}
	else
	{
		hash_remove("OLDPWD", table);
		remove_export_env("OLDPWD", environ);
	}
	return (0);
}
