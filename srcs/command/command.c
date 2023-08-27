/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:51:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 20:53:35 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "status.h"
#include "command.h"
#include "utils.h"

void		init_command(t_command *command);
t_command	*get_command(void);
void		clear_command(t_command *command);
void		free_command(t_command *command);

void	init_command(t_command *command)
{
	command->simple = 0;
	command->connection = 0;
	command->type = -1;
}

t_command	*get_command(void)
{
	t_command	*command;

	command = (t_command *)xmalloc(sizeof(t_command));
	init_command(command);
	return (command);
}

void	clear_command(t_command *command)
{
	if (command->simple)
		free_simple_com(command->simple);
	if (command->connection)
		free_connection(command->connection);
	init_command(command);
}

void	free_command(t_command *command)
{
	clear_command(command);
	free(command);
}
