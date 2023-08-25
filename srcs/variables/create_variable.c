/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:35:51 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 13:27:39 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "variables.h"
#include "utils.h"

t_variable	*create_variable(char *name, char *value);

t_variable	*create_variable(char *name, char *value)
{
	t_variable	*entry;

	entry = (t_variable *)xmalloc(sizeof(t_variable));
	entry->name = name;
	entry->value = value;
	return (entry);
}
