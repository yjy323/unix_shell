/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_export_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:30:31 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/26 20:20:00 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#include "hashlib.h"

int			find_export_env(char *name, char **export_env);
static bool	compare_export_env_name(char *name, char *str, int equal_sign_idx);

int	find_export_env(char *name, char **export_env)
{
	char	**iter;
	char	*str;
	int		array_idx;
	int		str_idx;

	iter = export_env;
	array_idx = 0;
	while (iter[array_idx])
	{
		str_idx = 0;
		str = iter[array_idx];
		while (str[str_idx])
		{
			if (str[str_idx] == '='
				&& compare_export_env_name(name, str, str_idx))
				return (array_idx);
			str_idx++;
		}
		array_idx++;
	}
	return (-1);
}

static bool	compare_export_env_name(char *name, char *str, int equal_sign_idx)
{
	str[equal_sign_idx] = 0;
	if (hash_str_equal(name, str))
	{
		str[equal_sign_idx] = '=';
		return (true);
	}
	else
	{
		str[equal_sign_idx] = '=';
		return (false);
	}
}
