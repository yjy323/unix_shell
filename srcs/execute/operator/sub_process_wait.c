/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_process_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:29:54 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 16:46:07 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>

#include "../../../includes/execute/operator.h"

void	sub_process_wait(t_pid_lst *head);

void	sub_process_wait(t_pid_lst *head)
{
	t_pid_lst	*sub_pid;
	int			status;
	extern int	g_status;

	g_status = 0;
	sub_pid = head->next;
	while (sub_pid)
	{
		waitpid(-1, &status, 0);
		sub_pid = sub_pid->next;
	}
}
