/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:49:37 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 13:26:55 by youjeong         ###   ########.fr       */
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
	new_table->bucket_array
		= (t_bucket_contents **)xmalloc (buckets * sizeof (t_bucket_contents *));
	new_table->nbuckets = buckets;
	new_table->nentries = 0;
	i = 0;
	while (i < buckets)
		new_table->bucket_array[i++] = (t_bucket_contents *)0;
	return (new_table);
}
