/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:48:13 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 21:06:01 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>	

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "utils.h"
#include "status.h"

int	execute_command(t_command *command);
int	execute_command_internal(t_command *command, int pre_in, int pre_out);
static char	*get_curr_cmd(t_word_list *list);

int	execute_command(t_command *command)
{
	execute_command_internal(command, -1, -1);
	return (0);
}
#include <stdio.h>
int	execute_command_internal(t_command *command, int pre_in, int pre_out)
{
	char	*curr_cmd;

	curr_cmd = 0;
	if (!command)
		return (1);
	if (command->type == cm_connection)
		execute_connection_command(command, curr_cmd, pre_in, pre_out);
	else if (command->type == cm_simple)
	{
		curr_cmd = get_curr_cmd(command->simple->words);
		if (curr_cmd)
			curr_cmd = ft_xstrdup(curr_cmd);
		execute_simple_command(command, curr_cmd, pre_in, pre_out);
		if (curr_cmd)
			free(curr_cmd);
	}
	return (0);
}

static char	*get_curr_cmd(t_word_list *list)
{
	if (!list || !list->word || !list->word->word)
		return (0);
	else
		return (list->word->word);
}
