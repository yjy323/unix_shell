/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:28:42 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 12:33:32 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "../../includes/execute.h"

void		wait_handler(t_cmd *cmd, t_type type, int pid);
void		wait_all_remain_process(t_pid_list *sub_pid_head);
static void	add_wait_list(t_pid_list *head, int pid);

void	wait_handler(t_cmd *cmd, t_type type, int pid)
{
	int	status;

	if (is_sequential_cmd(type) == true)
		waitpid(pid, &status, 0);
	else if (is_asynchronous_cmd(type) == true)
		waitpid(pid, &status, WNOHANG);
	else
		add_wait_list(cmd->sub_pid_head, pid);
}

void	wait_all_remain_process(t_pid_list *sub_pid_head)
{
	t_pid_list	*sub_pid;
	int			status;

	sub_pid = sub_pid_head->next;
	while (sub_pid)
	{
		waitpid(-1, &status, 0);
		sub_pid = sub_pid->next;
	}
}

static void	add_wait_list(t_pid_list *head, int pid)
{
	t_pid_list	*iter;
	t_pid_list	*new;

	new = malloc(sizeof(t_pid_list));
	if (!new)
		crash(errno);
	new->pid = pid;
	new->next = 0;
	iter = head;
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}
