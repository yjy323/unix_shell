/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:11:52 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/13 20:15:35 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/type.h"

void	destroy_cmd(t_cmd *cmd)
{
	t_pid_list	*pid;
	t_pid_list	*del_pid;

	if (cmd)
	{
		if (cmd->path)
			free(cmd->path);
		if (cmd->sub_pid_head)
			free_list(cmd->sub_pid_head);
	}
}
