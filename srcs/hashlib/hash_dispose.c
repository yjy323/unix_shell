/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_dispose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:50:46 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/09 04:02:47 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hashlib.h"

void	hash_dispose(t_hash_table *table);

void	hash_dispose(t_hash_table *table)
{
	free(table->bucket_array);
	free(table);
}
