/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_export_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:25:56 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 15:08:38 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "variables.h"

char	**remove_export_env(char *name, char **export_env);

char	**remove_export_env(char *name, char **export_env)
{
	int		idx;

	idx = find_export_env(name, export_env);
	if (idx != -1)
	{
		free(export_env[idx]);
		while (export_env[idx + 1])
		{
			export_env[idx] = export_env[idx + 1];
			idx++;
		}
		export_env[idx] = 0;
	}
	return (export_env);
}
