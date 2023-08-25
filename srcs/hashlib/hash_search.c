/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:17:42 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 15:07:24 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hashlib.h"

t_bucket_contents	*hash_search(
						const char *string, t_hash_table *table);

t_bucket_contents	*hash_search(
						const char *string, t_hash_table *table)
{
	t_bucket_contents	*list;
	int					bucket;
	unsigned int		hv;

	if (table == 0)
		return ((t_bucket_contents *)0);
	hv = hash_bucket (string, table);
	bucket = hv;
	if (table->bucket_array)
		list = table->bucket_array[bucket];
	else
		list = 0;
	while (list)
	{
		if (hv == list->khash && hash_str_equal(list->key, string))
			return (list);
		list = list->next;
	}
	return (0);
}
