/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_single_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:35:40 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 18:07:33 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#include "../../../includes/execute/operator.h"
#include "../../../includes/execute/command.h"

void		operate_single_command(t_node *command_node, t_compound *comp_exec);
static void	save_std_fd(int *p_save_stdin, int *p_save_stdout);
static void	close_std_fd(int save_stdin, int save_stdout);

void	operate_single_command(t_node *command_node, t_compound *comp_exec)
{
	int	save_stdin;
	int	save_stdout;

	save_std_fd(&save_stdin, &save_stdout);
	exec_redirect(command_node->right, save_stdout);
	exec_command(command_node->left, comp_exec);
	close_std_fd(save_stdin, save_stdout);
}

static void	save_std_fd(int *p_save_stdin, int *p_save_stdout)
{
	*p_save_stdin = dup(STDIN_FILENO);
	*p_save_stdout = dup(STDOUT_FILENO);
}

static void	close_std_fd(int save_stdin, int save_stdout)
{
	close(save_stdin);
	close(save_stdout);
}
