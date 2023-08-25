/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:17:33 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 19:01:47 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashlib.h"

t_bucket_contents	*hash_remove(
						const char *string, t_hash_table *table);

t_bucket_contents	*hash_remove(
						const char *string, t_hash_table *table)
{
	t_bucket_contents	*prev;
	t_bucket_contents	*temp;
	unsigned int		hv;

	hv = 0;
	if (table == 0 || table->nentries == 0)
		return ((t_bucket_contents *)0);
	hv = hash_bucket (string, table);
	prev = (t_bucket_contents *)0;
	temp = table->bucket_array[hv];
	while (temp)
	{
		if (hv == temp->khash && hash_str_equal (temp->key, string))
		{
			if (prev)
				prev->next = temp->next;
			else
				table->bucket_array[hv] = temp->next;
			table->nentries--;
			return (temp);
		}
		prev = temp;
		temp = temp->next;
	}
	return ((t_bucket_contents *) 0);
}
