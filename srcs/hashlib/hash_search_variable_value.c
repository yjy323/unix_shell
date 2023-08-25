/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search_variable_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:36:08 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 18:09:10 by youjeong         ###   ########.fr       */
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
	if (!bucket)
		return (0);
	value = ((t_variable *)bucket->data)->value;
	return (value);
}
