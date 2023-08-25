/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:17:37 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 13:27:32 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hashlib.h"
#include "utils.h"

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
	item = (t_bucket_contents *)xmalloc (sizeof(t_bucket_contents));
	item->next = table->bucket_array[bucket];
	item->data = 0;
	table->bucket_array[bucket] = item;
	item->key = string;
	item->khash = hv;
	return (item);
}
