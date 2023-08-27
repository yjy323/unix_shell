/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_export_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:03:26 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 21:01:20 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "hashlib.h"
#include "variables.h"
#include "utils.h"

char		**update_export_env(char *name,
				char *value, t_environment *environ, int flag);
static char	**update_export_env_internal(char *name,
				char *value, char **export_env);
static char	**add_export_env(char *name, char *value, t_environment *environ);
static char	*make_export_env(char *name, char *value);
static char	**resize_export_env(t_environment *environ);

char	**update_export_env(char *name,
			char *value, t_environment *environ, int flag)
{
	t_bucket_contents	*bucket;
	t_hash_table		*table;

	table = environ->env_table;
	bucket = hash_search(name, table);
	if (!bucket && flag == V_CREATE)
		environ->env_array = add_export_env(name, value, environ);
	else
		environ->env_array = update_export_env_internal(name,
				value, environ->env_array);
	return (environ->env_array);
}

static char	**update_export_env_internal(char *name,
				char *value, char **export_env)
{
	int	idx;

	idx = find_export_env(name, export_env);
	if (idx != -1)
	{
		free(export_env[idx]);
		export_env[idx] = make_export_env(name, value);
	}
	return (export_env);
}

static char	**add_export_env(char *name, char *value, t_environment *environ)
{
	size_t	idx;

	idx = 0;
	while (environ->env_array[idx])
		idx++;
	if (idx + 1 > environ->array_size)
		environ->env_array = resize_export_env(environ);
	environ->env_array[idx++] = make_export_env(name, value);
	environ->env_array[idx] = 0;
	return (environ->env_array);
}

static char	*make_export_env(char *name, char *value)
{
	size_t	new_len;
	char	*new_env;
	int		idx;

	idx = 0;
	new_len = ft_strlen(name) + ft_strlen(value) + 1;
	new_env = (char *)xmalloc(sizeof(char) * (new_len + 1));
	new_env[new_len] = 0;
	while (*name)
	{
		new_env[idx++] = *(name++);
	}
	new_env[idx++] = '=';
	while (*value)
		new_env[idx++] = *(value++);
	return (new_env);
}

static char	**resize_export_env(t_environment *environ)
{
	char	**new_export_env;
	size_t	idx;

	environ->array_size += 16;
	new_export_env = (char **)xmalloc(
			sizeof(char *) * (environ->array_size + 1));
	idx = 0;
	while (environ->env_array[idx])
	{
		new_export_env[idx] = environ->env_array[idx];
		idx++;
	}
	free(environ->env_array);
	return (new_export_env);
}
