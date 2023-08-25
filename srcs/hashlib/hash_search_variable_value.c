/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search_variable_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:36:08 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 15:22:19 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashlib.h"
#include "variables.h"

char	*hash_search_variable_value(char *key, t_hash_table *table)
{
	t_bucket_contents	*bucket;
	char				*value;

	value = 0;
	bucket = hash_search(key, table);
	value = ((t_variable *)bucket->data)->value;
	return (value);
}
