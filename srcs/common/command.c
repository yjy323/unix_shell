/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:51:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/11 15:46:47 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"

void		init_command(t_command *command);
t_command	*get_command(void);
void		clear_command(t_command *command);
static void	free_command_recursive(t_command *command);
void		free_command(t_command *command);

void	init_command(t_command *command)
{
	command->first = 0;
	command->second = 0;
	command->simple = 0;
	command->type = -1;
}

t_command	*get_command(void)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		crash(ENOMEM, 0);
	init_command(command);
	return (command);
}

void	clear_command(t_command *command)
{
	free_command_recursive(command->first);
	free_command_recursive(command->second);
	free_simple_com(command->simple);
	init_command(command);
}

static void	free_command_recursive(t_command *command)
{
	if (!command)
		return ;
	free_command_recursive(command->first);
	free_command_recursive(command->second);
	free_simple_com(command->simple);
	free(command);
}

void	free_command(t_command *command)
{
	clear_command(command);
	free(command);
}
