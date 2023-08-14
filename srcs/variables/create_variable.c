/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:35:51 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/11 20:17:04 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "variables.h"

t_variable	*create_variable(char *name, char *value);

t_variable	*create_variable(char *name, char *value)
{
	t_variable	*entry;

	entry = (t_variable *)malloc(sizeof(t_variable));
	entry->name = name;
	entry->value = value;
	return (entry);
}
