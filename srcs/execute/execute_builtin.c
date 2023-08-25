/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:42:09 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 20:35:55 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"

#include "libft.h"

int	execute_buitin(t_word_list *words);

int	execute_buitin(t_word_list *words)
{
	int			status;
	int			len;
	char		*command;
	t_word_list	*argument;

	command = words->word->word;
	argument = words->next;
	len = ft_strlen(command);
	if (!ft_strncmp(command, "cd", len))
		status = ft_cd(argument);
	else if (!ft_strncmp(command, "echo", len))
		status = ft_echo(argument);
	else if (!ft_strncmp(command, "env", len))
		status = ft_env(argument);
	else if (!ft_strncmp(command, "exit", len))
		status = ft_exit(argument);
	else if (!ft_strncmp(command, "export", len))
		status = ft_export(argument);
	else if (!ft_strncmp(command, "pwd", len))
		status = ft_pwd();
	else if (!ft_strncmp(command, "unset", len))
		status = ft_unset(argument);
	else
		status = ENOCMD;
	return (status);
}
