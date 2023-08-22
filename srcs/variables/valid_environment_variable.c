/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_environment_variable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:43:53 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/22 17:34:27 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft.h"

bool	valid_env_variable(char *name)
{
	int i;

	if (ft_isdigit(*name))
		return (1);
	i = 0;
	while (name[i])
	{
		if (ft_isalnum(name[i])
			|| name[i] != '_')
			return (1);
		i++;
	}
	return (0);
}
