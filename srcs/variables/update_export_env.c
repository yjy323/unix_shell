/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_export_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:03:26 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/11 22:29:22 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hashlib.h"
#include "variables.h"
#include "libft.h"

extern char	**environ;

char		**update_export_env(char *name, char *value, t_hash_table *table, int flag);
static char	**update_export_env_internal(char *name, char *value, char **export_env);
static char	**add_export_env(char *name, char *value, char **export_env);
static char	*make_export_env(char *name, char *value);
static char	**resize_export_env(char **export_env, size_t export_env_size);

char	**update_export_env(char *name, char *value, t_hash_table *table, int flag)
{
	char				**export_env;
	t_bucket_contents	*bucket;

	export_env = environ;
	bucket = hash_search(name, table);
	if (!bucket && flag == V_CREATE)
		add_export_env(name, value, export_env);
	else
		update_export_env_internal(name, value, export_env);
	environ = export_env;
	return (export_env);
}

static char	**update_export_env_internal(char *name, char *value, char **export_env)
{
	int	idx;

	idx = find_export_env(name, export_env);
	if (idx != -1)
	{
		// free(export_env[idx]);
		export_env[idx] = make_export_env(name, value);
	}
	return (export_env);
}

static char	**add_export_env(char *name, char *value, char **export_env)
{
	size_t	export_env_size;
	size_t	export_env_idx;
	char	***p_export_env;

	p_export_env = &export_env;
	export_env_size = 0;
	while (p_export_env[export_env_size])
		export_env_size++;
	export_env_idx = 0;
	while (export_env[export_env_idx])
		export_env_idx++;
	if (export_env_idx + 1 > export_env_size)
		export_env = resize_export_env(export_env, export_env_size);
	export_env[export_env_idx] = make_export_env(name, value);
	return (export_env);
}
#include <stdio.h>
static char	*make_export_env(char *name, char *value)
{
	size_t	new_len;
	char	*new_env;
	int		idx;

	idx = 0;
	new_len = ft_strlen(name) + ft_strlen(value) + 1;
	new_env = (char *)malloc(sizeof(char) * (new_len + 1));
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

static char	**resize_export_env(char **export_env, size_t export_env_size)
{
	char	**new_export_env;
	size_t	idx;

	export_env_size += 16;
	new_export_env = (char **)malloc(sizeof(char *) * (export_env_size + 1));
	idx = 0;
	while (export_env[idx])
	{
		new_export_env[idx] = export_env[idx];
		idx ++;
	}
	//free(export_env);
	return (new_export_env);
}
