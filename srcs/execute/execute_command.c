/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:48:13 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 15:36:53 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "utils.h"
#include "status.h"

int	execute_command(t_command *command, t_environment *environ);
int	execute_command_internal(t_command *command,
		t_environment *environ, int pre_in, int pre_out);

int	execute_command(t_command *command, t_environment *environ)
{
	g_status = execute_command_internal(command, environ, -1, -1);
	return (g_status);
}

int	execute_command_internal(t_command *command,
		t_environment *environ, int pre_in, int pre_out)
{
	if (!command)
		return (g_status);
	if (command->type == cm_connection)
		g_status = execute_connection_command(command,
				environ, pre_in, pre_out);
	else if (command->type == cm_simple)
	{
		if (!command->simple->words
			|| !command->simple->words->word || !command->simple->words->word)
			return (g_status);
		else
			g_status = execute_simple_command(command,
					environ, pre_in, pre_out);
	}
	return (g_status);
}
