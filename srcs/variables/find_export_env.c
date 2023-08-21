/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_export_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:30:31 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/11 22:04:00 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "hashlib.h"

int	find_export_env(char *name, char **export_env);

int	find_export_env(char *name, char **export_env)
{
	char	**iter;
	char	*str;
	int		idx;

	iter = export_env;
	while (*iter)
	{
		idx = 0;
		str = *iter;
		while (str[idx])
		{
			if (str[idx] == '=')
			{
				str[idx] = 0;
				if (hash_str_equal(name, str))
				{
					str[idx] = '=';
					return (idx);
				}
				str[idx] = '=';
			}
			idx++;
		}
		iter++;
	}
	return (-1);
}
