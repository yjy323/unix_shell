/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:22:00 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/21 22:51:24 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"
#include "hashlib.h"
#include "libft.h"

t_variable			*bind_variable(char *name, char *value, t_hash_table *table, int flag);
static t_variable	*hash_lookup(char *key, t_hash_table *table);

t_variable	*bind_variable(char *name, char *value, t_hash_table *table, int flag)
{
	t_bucket_contents	*bucket;
	t_variable			*entry;

	entry = hash_lookup(name, table);
	if (!entry && flag == V_CREATE)
	{
		bucket = hash_insert(ft_strdup(name), table);
		entry = create_variable(ft_strdup(name), ft_strdup(value));
		bucket->data = (void *)entry;
	}
	else
	{
		if (entry)
		{
			free(entry->value);
			entry->value = ft_strdup(value);
		}
	}
	return (entry);
}

static t_variable	*hash_lookup(char *key, t_hash_table *table)
{
	t_bucket_contents	*bucket;

	bucket = hash_search(key, table);
	if (bucket)
		return ((t_variable *)bucket->data);
	else
		return (0);
}
