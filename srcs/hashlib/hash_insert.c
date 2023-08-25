/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:17:37 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 15:06:59 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hashlib.h"

t_bucket_contents	*hash_insert(char *string, t_hash_table *table);

t_bucket_contents	*hash_insert(char *string, t_hash_table *table)
{
	t_bucket_contents	*item;
	int					bucket;
	unsigned int		hv;

	if (table == 0)
		table = hash_create (0);
	table->nentries++;
	if (hash_shouldgrow (table))
		hash_grow (table);
	hv = hash_bucket (string, table);
	bucket = hv;
	item = (t_bucket_contents *)malloc (sizeof(t_bucket_contents));
	item->next = table->bucket_array[bucket];
	item->data = 0;
	table->bucket_array[bucket] = item;
	item->key = string;
	item->khash = hv;
	return (item);
}
