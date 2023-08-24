/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:22:00 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 17:56:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"
#include "hashlib.h"
#include "libft.h"
#include "utils.h"

t_variable			*bind_variable(char *name, char *value, t_hash_table *table, int flag);
static t_variable	*hash_lookup(char *key, t_hash_table *table);

t_variable	*bind_variable(char *name, char *value, t_hash_table *table, int flag)
{
	t_bucket_contents	*bucket;
	t_variable			*entry;

	entry = hash_lookup(name, table);
	if (!entry && flag == V_CREATE)
	{
		bucket = hash_insert(ft_xstrdup(name), table);
		entry = create_variable(ft_xstrdup(name), ft_xstrdup(value));
		bucket->data = (void *)entry;
	}
	else
	{
		if (entry)
		{
			free(entry->value);
			entry->value = ft_xstrdup(value);
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
