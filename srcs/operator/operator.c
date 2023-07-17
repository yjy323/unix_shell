/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:36:50 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 19:09:35 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operator.h"

void	set_ipc(t_node *node, t_cmd *cmd);
void	operator_main_process(t_node *parent_node, t_cmd *cmd);
void	operator_sub_process(t_node *parent_node, t_cmd *cmd);

void	set_ipc(t_node *node, t_cmd *cmd)
{
	if (!node->parent)
		return ;
	else if (node->parent->data->type == PIPELINE && !cmd->flag_last_cmd)
	{
		if (pipe(cmd->fd) == ERROR)
			crash(errno);
	}
}

void	operator_main_process(t_node *parent_node, t_cmd *cmd)
{
	if (!parent_node)
		return ;
	else if (parent_node->data->type == PIPELINE)
		pipe_main_process(cmd);
	else
		return ;
}

void	operator_sub_process(t_node *parent_node, t_cmd *cmd)
{
	if (!parent_node)
		return ;
	else if (parent_node->data->type == PIPELINE)
		pipe_sub_process(cmd);
	else
		return ;
}
