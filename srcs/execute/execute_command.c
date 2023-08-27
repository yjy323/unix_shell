/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:48:13 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:56:32 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "status.h"
#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "utils.h"

int	execute_command(t_command *command);
int	execute_command_internal(t_command *command, int pre_in, int pre_out);

int	execute_command(t_command *command)
{
	execute_command_internal(command, -1, -1);
	return (0);
}

int	execute_command_internal(t_command *command, int pre_in, int pre_out)
{
	int	status;

	status = SUCCESS;
	if (!command)
		return (1);
	if (command->type == cm_connection)
		status = execute_connection_command(command, pre_in, pre_out);
	else if (command->type == cm_simple)
		status = execute_simple_command(command, pre_in, pre_out);
	g_sh_variable.status = status;
	return (status);
}
