/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_process_add_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:29:51 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 23:21:25 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../../includes/execute/operator.h"

void	sub_process_add_lst(t_pid_lst *head, int pid);

void	sub_process_add_lst(t_pid_lst *head, int pid)
{
	t_pid_lst	*iter;
	t_pid_lst	*new;

	new = malloc(sizeof(t_pid_lst));
	if (!new)
		crash("malloc()", errno);
	new->pid = pid;
	new->next = 0;
	iter = head;
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}
