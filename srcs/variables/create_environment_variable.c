/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environment_variable.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:37:51 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 21:01:03 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "variables.h"
#include "hashlib.h"
#include "utils.h"

t_environment	*create_environment_variable(char **initial_environ);
static void		create_environment_variable_contents(char **initial_environ,
					t_environment *env, int size);
static int		get_environ_size(char **environ);
static char		*get_name(char *exported_env);
static char		*get_value(char *exported_env);

t_environment	*create_environment_variable(char **initial_environ)
{
	t_environment	*env;
	int				size;

	env = xmalloc(sizeof(t_environment));
	size = get_environ_size(initial_environ);
	env->env_table = hash_create(size * HASH_REHASH_MULTIPLIER);
	env->env_array = xmalloc(sizeof(char *) * (size + 1));
	env->array_size = size;
	env->env_array[size] = 0;
	create_environment_variable_contents(initial_environ, env, size);
	return (env);
}

static void	create_environment_variable_contents(char **initial_environ,
				t_environment *env, int size)
{
	int				i;
	char			*name;
	char			*value;

	i = 0;
	while (i < size)
	{
		name = get_name(initial_environ[i]);
		value = get_value(initial_environ[i]);
		bind_variable(name, value, env->env_table, V_CREATE);
		env->env_array[i] = ft_xstrdup(initial_environ[i]);
		free(name);
		free(value);
		i++;
	}
	return ;
}

static int	get_environ_size(char **environ)
{
	int	size;

	size = 0;
	while (environ[size])
		size++;
	return (size);
}

static char	*get_name(char *exported_env)
{
	int		i;
	char	*name;

	i = 0;
	name = 0;
	while (exported_env[i])
	{
		if (exported_env[i] == '=')
		{
			exported_env[i] = 0;
			name = ft_xstrdup(exported_env);
			exported_env[i] = '=';
			break ;
		}
		i++;
	}
	return (name);
}

static char	*get_value(char *exported_env)
{
	int		i;
	char	*value;

	i = 0;
	value = 0;
	while (exported_env[i])
	{
		if (exported_env[i] == '=')
		{
			value = ft_xstrdup(exported_env + (i + 1));
			break ;
		}
		i++;
	}
	return (value);
}
