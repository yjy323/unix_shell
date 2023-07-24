/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:30:41 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 17:36:19 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "../includes/execute/execute.h"

void				execute(t_node *parsed, char ***p_envirion);
static int			exec_operator(t_node *command_node, t_compound *comp_exec);
static void			read_parse_tree_recurrsive(t_node *parsed,
						t_compound *comp_exec);
static t_compound	*initialize(char ***p_envirion);
static void			destroy(t_compound *comp);

void	execute(t_node *parsed, char ***p_envirion)
{
	t_compound	*comp_exec;
	extern int	g_status;

	comp_exec = initialize(p_envirion);
	read_parse_tree_recurrsive(parsed, comp_exec);
	destroy(comp_exec);
	exit(g_status);
}

static int	exec_operator(t_node *command_node, t_compound *comp_exec)
{
	t_type	type;

	if (!command_node->parent)
		operate_single_command(command_node, comp_exec);
	type = command_node->parent->data->type;
	if (type == PIPELINE)
		operate_pipe(command_node, comp_exec);
	return (0);
}

static void	read_parse_tree_recurrsive(t_node *parsed, t_compound *comp_exec)
{
	if (!parsed)
		return ;
	else if (parsed->data->type == COMMAND)
		exec_operator(parsed, comp_exec);
	read_parse_tree_recurrsive(parsed->left, comp_exec);
	read_parse_tree_recurrsive(parsed->right, comp_exec);
}

static t_compound	*initialize(char ***p_envirion)
{
	t_compound	*comp;

	comp = malloc(sizeof(t_compound));
	comp->cmd = malloc(sizeof(t_cmd));
	comp->cmd_pid_lst = malloc(sizeof(t_pid_lst));
	comp->op = malloc(sizeof(t_operator));
	comp->p_environ = p_envirion;
	if (!comp->cmd
		|| !comp->cmd_pid_lst
		|| !comp->op)
		crash("malloc()", errno);
	comp->op->fd[0] = STDIN_FILENO;
	comp->op->fd[1] = STDOUT_FILENO;
	comp->op->pre_fd[0] = STDIN_FILENO;
	comp->op->pre_fd[1] = STDOUT_FILENO;
	return (comp);
}

static void	destroy(t_compound *comp)
{
	t_pid_lst	*iter_lst;
	t_pid_lst	*del_lst;

	if (comp)
	{
		if (comp->cmd)
			free(comp->cmd);
		if (comp->cmd_pid_lst)
		{
			iter_lst = comp->cmd_pid_lst;
			while (iter_lst)
			{
				del_lst = iter_lst;
				iter_lst = iter_lst->next;
				free(del_lst);
			}
		}
		if (comp->op)
			free(comp->op);
		free(comp);
	}
}
