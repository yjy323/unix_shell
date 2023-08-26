/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_environment_variable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:21:01 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/26 19:16:17 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hashlib.h"
#include "variables.h"

void		destroy_environment_variable(t_environment *environ);
static void	destroy_environment_table(t_hash_table *table);
static void	destroy_environment_array(char **array);

void	destroy_environment_variable(t_environment *environ)
{
	if (environ)
	{
		destroy_environment_table(environ->env_table);
		destroy_environment_array(environ->env_array);
		free(environ);
	}
}

static void	destroy_environment_table(t_hash_table *table)
{
	int					i;
	t_bucket_contents	*bucket;
	t_bucket_contents	*del;
	t_variable			*var;

	i = 0;
	while (i < table->nbuckets)
	{
		if (table->bucket_array[i])
		{
			bucket = table->bucket_array[i];
			while (bucket)
			{
				del = bucket;
				var = (t_variable *)bucket->data;
				dispose_variable(var);
				bucket = bucket->next;
				free(del->key);
				free(del);
			}
		}
		i++;
	}
	hash_dispose(table);
}

static void	destroy_environment_array(char **array)
{
	int		i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
