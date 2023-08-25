/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:49:37 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 15:58:30 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hashlib.h"
#include "utils.h"

t_hash_table	*hash_create(int buckets);

t_hash_table	*hash_create(int buckets)
{
	t_hash_table	*new_table;
	int				i;

	new_table = (t_hash_table *)xmalloc(sizeof (t_hash_table));
	if (buckets == 0)
		buckets = 0;
	new_table->bucket_array = (t_bucket_contents **)xmalloc(
			buckets * sizeof (t_bucket_contents *));
	new_table->nbuckets = buckets;
	new_table->nentries = 0;
	i = 0;
	while (i < buckets)
		new_table->bucket_array[i++] = (t_bucket_contents *)0;
	return (new_table);
}
