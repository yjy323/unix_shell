/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:22:19 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 17:13:47 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

#include "../../../includes/execute/command.h"
#include "../../../includes/builtin/builtin.h"
#include "../../../libft/includes/libft.h"

void		exec_command(t_node *command_node, t_compound *comp_exec);
static void	exec_builtin(char **args);
static void	exec_external_file(t_compound *comp_exec);
static char	**set_cmd_args(t_node *command_node);
static char	*search_exec_file_path(char *file);

void	exec_command(t_node *command_node, t_compound *comp_exec)
{
	extern int	g_status;

	comp_exec->cmd->args = set_cmd_args(command_node->left);
	exec_builtin(comp_exec->cmd->args);
	if (g_status == ENOCMD)
	{
		comp_exec->cmd->exec_path = search_exec_file_path(
				comp_exec->cmd->args[0]);
		exec_external_file(comp_exec);
	}
	if (comp_exec->cmd->exec_path)
		free(comp_exec->cmd->exec_path);
	if (comp_exec->cmd->args)
		while (*comp_exec->cmd->args)
			free(*(comp_exec->cmd->args++));
}

static void	exec_builtin(char **args)
{
	extern int	g_status;
	int			len;
	char		*cmd_name;

	cmd_name = args[0];
	len = ft_strlen(cmd_name);
	if (!ft_strncmp(cmd_name, "cd", len))
		g_status = ft_cd();
	else if (!ft_strncmp(cmd_name, "echo", len))
		g_status = ft_echo();
	else if (!ft_strncmp(cmd_name, "env", len))
		g_status = ft_env();
	else if (!ft_strncmp(cmd_name, "exit", len))
		g_status = ft_exit();
	else if (!ft_strncmp(cmd_name, "export", len))
		g_status = ft_export();
	else if (!ft_strncmp(cmd_name, "pwd", len))
		g_status = ft_pwd();
	else if (!ft_strncmp(cmd_name, "unset", len))
		g_status = ft_unset();
	else
		g_status = ENOCMD;
}

static void	exec_external_file(t_compound *comp_exec)
{
	extern int	g_status;
	t_cmd		*cmd;
	int			pid;
	int			status;

	cmd = comp_exec->cmd;
	pid = fork();
	if (pid == -1)
		crash(comp_exec->cmd->args[0], errno);
	else if (pid == 0)
		execve(cmd->exec_path, cmd->args, *comp_exec->p_environ);
	else
	{
		waitpid(pid, &status, 0);
		g_status = status;
	}
}

static char	**set_cmd_args(t_node *command_node)
{
	char	**args;
	t_node	*iter;
	int		cnt;
	int		i;

	iter = command_node;
	cnt = 0;
	while (iter)
	{
		iter = iter->right;
		cnt++;
	}
	args = malloc(sizeof(char *) * (cnt + 1));
	if (!args)
		crash(command_node->data->word, errno);
	args[cnt] = NULL;
	i = 0;
	while (i < cnt)
	{
		args[i] = ft_strdup(command_node->data->word);
		if (!args[i++])
			crash(command_node->data->word, errno);
		command_node = command_node->right;
	}
	return (args);
}

static char	*search_exec_file_path(char *file)
{
	char	*rel_path_file;
	char	*exec_file;
	char	**path;
	char	*del;

	if (access(file, F_OK) == 0)
		return (file);
	del = getenv("PATH");
	path = ft_split(ft_strchr(del, '=') + 1, ':');
	rel_path_file = ft_strjoin("/", file);
	if (!rel_path_file)
		crash(file, errno);
	while (*path)
	{
		free(del);
		del = *path;
		exec_file = ft_strjoin(*path++, rel_path_file);
		if (!exec_file)
			crash(file, errno);
		else if (access(exec_file, F_OK) == 0)
			break ;
		free(exec_file);
	}
	free(rel_path_file);
	return (file);
}
