/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:48:13 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/22 12:39:04 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"

extern int	g_status;

int	execute_command(t_command *command, t_environment *environ);
int	execute_command_internal(t_command *command, t_environment *environ, int pre_in, int pre_out);

int	execute_command(t_command *command, t_environment *environ)
{
	g_status = execute_command_internal(command, environ, -1, -1);
	return (g_status);
}

int	execute_command_internal(t_command *command, t_environment *environ, int pre_in, int pre_out)
{
	char	*word;

	if (!command)
		return (g_status);
	if (command->type == cm_connection)
	{
		g_status = execute_connection_command(command, environ, pre_in, pre_out);
	}
	else if (command->type == cm_simple)
	{
		g_status = execute_simple_command(command, environ, pre_in, pre_out);
		word = command->simple->words->word->word;
	}
	else
	{
		g_status = 1;
		word = 0;
	}
	if (g_status != 0)
		crash(g_status, word);
	return (g_status);
}
