/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_shouldgrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:54:21 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/09 04:03:00 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashlib.h"

t_bool	hash_shouldgrow(t_hash_table *table);

t_bool	hash_shouldgrow(t_hash_table *table)
{
	if (table->nentries >= table->nbuckets * HASH_REHASH_FACTOR)
		return (true);
	else
		return (false);
}
