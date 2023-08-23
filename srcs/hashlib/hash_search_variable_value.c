/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search_variable_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:36:08 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 18:40:08 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashlib.h"
#include "variables.h"

char	*hash_search_variable_value(char *key, t_hash_table *table)
{
	t_bucket_contents	*bucket;
	char				*value;

	bucket = hash_search(key, table);
	value = ((t_variable *)bucket->data)->value;
	return (value);
}
