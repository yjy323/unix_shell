/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_first_operate_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:12:03 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 16:30:27 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/execute/operator.h"

bool	is_first_operate_cmd(t_node *command_node, t_type type);

bool	is_first_operate_cmd(t_node *command_node, t_type type)
{
	t_node	*opertor;
	t_node	*pre_parsed;

	opertor = command_node->parent;
	pre_parsed = command_node->left;
	if (opertor->left == command_node)
	{
		if (!pre_parsed)
			return (true);
		else if (pre_parsed->data->type != type)
			return (true);
		else
			return (false);
	}
	else
		return (false);
}
