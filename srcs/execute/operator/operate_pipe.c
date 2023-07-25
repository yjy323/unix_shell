/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:56:10 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/25 14:44:55 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "../../../includes/execute/operator.h"
#include "../../../includes/execute/command.h"

void		operate_pipe(t_node *command_node, t_compound *comp_exec);
static void	sub_process(t_node *command_node,
				t_compound *comp_exec, bool is_first, bool is_last);
static void	main_process(t_compound *comp_exec,
				int pid, bool is_first, bool is_last);
static void	redirect_pipe(t_operator *op, bool is_first, bool is_last);
static void	close_unused_pipe(t_operator *op, bool is_first, bool is_last);

void	operate_pipe(t_node *command_node, t_compound *comp_exec)
{
	int		pid;
	bool	is_first;
	bool	is_last;

	is_first = is_first_operate_cmd(command_node, PIPELINE);
	is_last = is_last_operate_cmd(command_node, PIPELINE);
	if (is_last == false)
		pipe(comp_exec->op->fd);
	pid = fork();
	if (pid == 0)
		sub_process(command_node, comp_exec, is_first, is_last);
	else
		main_process(comp_exec, pid, is_first, is_last);
}

static void	sub_process(t_node *command_node,
				t_compound *comp_exec, bool is_first, bool is_last)
{
	int			save_stdout;
	extern int	g_status;

	save_stdout = dup(STDOUT_FILENO);
	redirect_pipe(comp_exec->op, is_first, is_last);
	exec_redirect(command_node->right, save_stdout);
	close(save_stdout);
	exec_command(command_node->left, comp_exec);
	exit(g_status);
}

static void	main_process(t_compound *comp_exec,
				int pid, bool is_first, bool is_last)
{
	close_unused_pipe(comp_exec->op, is_first, is_last);
	comp_exec->op->pre_fd[0] = comp_exec->op->fd[0];
	comp_exec->op->pre_fd[1] = comp_exec->op->fd[1];
	if (is_last == true)
		sub_process_wait(comp_exec->cmd_pid_lst);
	else
		sub_process_add_lst(comp_exec->cmd_pid_lst, pid);
}

static void	redirect_pipe(t_operator *op, bool is_first, bool is_last)
{
	if (is_first == true)
	{
		if (close(op->fd[0]) == ERROR
			|| dup2(op->fd[1], STDOUT_FILENO) == ERROR)
			crash("Redirection pipe", errno);
	}
	else if (is_last == true)
	{
		if (dup2(op->pre_fd[0], STDIN_FILENO) == ERROR)
			crash("Redirection pipe", errno);
	}
	else
	{
		if (close(op->fd[0]) == ERROR
			|| dup2(op->pre_fd[0], STDIN_FILENO) == ERROR
			|| dup2(op->fd[1], STDOUT_FILENO) == ERROR)
			crash("Redirection pipe", errno);
	}
}

static void	close_unused_pipe(t_operator *op, bool is_first, bool is_last)
{
	if (is_first == true)
	{
		if (close(op->fd[1]) == ERROR)
			crash("Close pipe", errno);
	}
	else if (is_last == true)
	{
		if (close(op->pre_fd[0]) == ERROR)
			crash("Close pipe", errno);
	}
	else
	{
		if (close(op->fd[1]) == ERROR
			|| close(op->pre_fd[0]) == ERROR)
			crash("Close pipe", errno);
	}
}
