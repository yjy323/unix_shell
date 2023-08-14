/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:01:35 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/11 20:08:35 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "variables.h"

void	dispose_variable(t_variable *entry);

void	dispose_variable(t_variable *entry)
{
	if (entry)
	{
		if (entry->name)
			free(entry->name);
		if (entry->value)
			free(entry->value);
		free(entry);
	}
}
