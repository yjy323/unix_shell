/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:17:10 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 18:39:13 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHLIB_H
# define HASHLIB_H

# include <stdbool.h>

# include "command.h"

# define HASH_REHASH_MULTIPLIER	4
# define HASH_REHASH_FACTOR	2

# define FNV_OFFSET 2166136261
# define FNV_PRIME 16777619

typedef struct s_bucket_contents {
	struct s_bucket_contents	*next;
	char						*key;
	void						*data;
	unsigned int				khash;
}	t_bucket_contents;

typedef struct s_hash_table {
	t_bucket_contents	**bucket_array;
	int					nbuckets;
	int					nentries;
}	t_hash_table;

t_hash_table		*hash_create(int buckets);
void				hash_dispose(t_hash_table *table);
void				hash_grow(t_hash_table *table);
bool				hash_shouldgrow(t_hash_table *table);

int					hash_bucket(const char *string, t_hash_table *table);
t_bucket_contents	*hash_search(
						const char *string, t_hash_table *table);
t_bucket_contents	*hash_remove(
						const char *string, t_hash_table *table);
t_bucket_contents	*hash_insert(char *string, t_hash_table *table);

bool				hash_str_equal(const char *key, const char *string);
char				*hash_search_variable_value(char *key, t_hash_table *table);

#endif
