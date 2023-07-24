/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_operate_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:12:04 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 16:30:29 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/execute/operator.h"

bool	is_last_operate_cmd(t_node *command_node, t_type type);

bool	is_last_operate_cmd(t_node *command_node, t_type type)
{
	t_node	*opertor;
	t_node	*next_parsed;

	opertor = command_node->parent;
	next_parsed = opertor->parent;
	if (opertor->right == command_node)
	{
		if (!next_parsed)
			return (true);
		else if (next_parsed->data->type != type)
			return (true);
		else
			return (false);
	}
	else
		return (false);
}
