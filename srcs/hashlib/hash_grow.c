/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_grow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:16:33 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 13:27:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hashlib.h"
#include "utils.h"

void		hash_grow(t_hash_table *table);
static void	hash_rehash(t_hash_table *table, int nsize);
static void	copy_bucket(t_hash_table *table,
				t_bucket_contents **old_bucket_array, int osize);

void	hash_grow(t_hash_table *table)
{
	int	nsize;

	nsize = table->nbuckets * HASH_REHASH_MULTIPLIER;
	if (nsize > 0)
		hash_rehash(table, nsize);
}

static void	hash_rehash(t_hash_table *table, int nsize)
{
	int					osize;
	int					i;
	t_bucket_contents	**old_bucket_array;

	if (table == 0 || nsize == table->nbuckets)
		return ;
	osize = table->nbuckets;
	old_bucket_array = table->bucket_array;
	table->nbuckets = nsize;
	table->bucket_array = (t_bucket_contents **)xmalloc(
			table->nbuckets * sizeof (t_bucket_contents *));
	i = 0;
	while (i < table->nbuckets)
		table->bucket_array[i++] = (t_bucket_contents *)0;
	copy_bucket(table, old_bucket_array, osize);
	free (old_bucket_array);
}

static void	copy_bucket(t_hash_table *table,
				t_bucket_contents **old_bucket_array, int osize)
{
	int					i;
	int					j;
	t_bucket_contents	*item;
	t_bucket_contents	*next;

	j = 0;
	while (j < osize)
	{
		item = old_bucket_array[j];
		while (item)
		{
			next = item->next;
			i = item->khash & (table->nbuckets - 1);
			item->next = table->bucket_array[i];
			table->bucket_array[i] = item;
			item = next;
		}
	}
}
