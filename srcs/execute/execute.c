/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:30:41 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 20:07:43 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		execute(t_node *node, t_cmd *cmd);
static void	execute_command(t_node *node, t_cmd *cmd);
static void	execute_multiple_command_recurrsive(t_node *node, t_cmd *cmd);
static void	exec_builtin(char *cmd_name);
static void	exec_file(t_node *node, t_cmd *cmd);

void	execute(t_node *node, t_cmd *cmd)
{
	if (is_single_command(node))
		execute_command(node, cmd);
	else
		execute_multiple_command_recurrsive(node, cmd);
	wait_all_remain_process(cmd->sub_pid_head);
	if (access(".here_doc", F_OK) == 0)
		unlink(".here_doc");
}

static void	execute_command(t_node *node, t_cmd *cmd)
{
	int	pid;
	int	fd_stdout;

	set_ipc(node, cmd);
	pid = fork();
	if (pid == ERROR)
		crash(cmd->args[0], errno);
	else if (pid == 0)
	{
		fd_stdout = dup(STDOUT_FILENO);
		operator_sub_process(node->parent, cmd);
		redirect(node->right, fd_stdout);
		if (is_builtin(node->data->word) == true)
			exec_builtin(node->data->word);
		else
			exec_file(node->left, cmd);
	}
	else
	{
		operator_main_process(node->parent, cmd);
		wait_handler(cmd, node->data->type, pid);
	}
}

static void	execute_multiple_command_recurrsive(t_node *node, t_cmd *cmd)
{
	if (!node || node->data->type == COMMAND)
		return ;
	execute_multiple_command_recurrsive(node->left, cmd);
	if (node->left->data->type == COMMAND)
	{
		execute_command(node->left, cmd);
		cmd->flag_first_cmd = false;
	}
	execute_multiple_command_recurrsive(node->right, cmd);
	cmd->flag_last_cmd = is_last_command(node);
	if (node->right->data->type == COMMAND)
		execute_command(node->right, cmd);
	return ;
}

static void	exec_builtin(char *cmd_name)
{
	int	len;

	len = ft_strlen(cmd_name);
	if (!ft_strncmp(cmd_name, "cd", len))
		ft_cd();
	else if (!ft_strncmp(cmd_name, "echo", len))
		ft_echo();
	else if (!ft_strncmp(cmd_name, "env", len))
		ft_env();
	else if (!ft_strncmp(cmd_name, "exit", len))
		ft_exit();
	else if (!ft_strncmp(cmd_name, "export", len))
		ft_export();
	else if (!ft_strncmp(cmd_name, "pwd", len))
		ft_pwd();
	else if (!ft_strncmp(cmd_name, "unset", len))
		ft_unset();
}

static void	exec_file(t_node *node, t_cmd *cmd)
{
	if (!node)
		exit(0);
	cmd->args = set_cmd_args(node);
	cmd->cmd_path = set_cmd_path(cmd->args[0], cmd->path);
	if (execve(cmd->cmd_path, cmd->args, cmd->envp) == ERROR)
		crash(cmd->args[0], errno);
}
