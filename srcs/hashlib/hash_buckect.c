/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_buckect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:52:05 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/09 04:02:43 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashlib.h"

int					hash_bucket(const char *string, t_hash_table *table);
static unsigned int	hash_string(const char *s);

int	hash_bucket(const char *string, t_hash_table *table)
{
	return (hash_string (string) & table->nbuckets - 1);
}

static unsigned int	hash_string(const char *s)
{
	unsigned int	i;

	i = FNV_OFFSET;
	while (*s)
	{
		i *= FNV_PRIME;
		i ^= *s;
		s++;
	}
	return (i);
}
