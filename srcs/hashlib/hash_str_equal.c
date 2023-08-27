/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_str_equal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:44:41 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:59:08 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#include "libft.h"

#include "command.h"

bool	hash_str_equal(const char *key, const char *string);

bool	hash_str_equal(const char *key, const char *string)
{
	size_t	key_len;
	size_t	string_len;

	key_len = ft_strlen(key);
	string_len = ft_strlen(string);
	if (key_len == string_len
		&& !ft_strncmp(key, string, key_len))
		return (true);
	else
		return (false);
}
