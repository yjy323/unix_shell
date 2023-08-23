/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:42:09 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 04:19:24 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"

#include "libft.h"

extern int	g_status;

int	execute_buitin(t_word_list *words, t_environment *environ);

int	execute_buitin(t_word_list *words, t_environment *environ)
{
	int			status;
	int			len;
	char		*command;
	t_word_list	*argument;

	command = words->word->word;
	argument = words->next;
	len = ft_strlen(command);
	if (!ft_strncmp(command, "cd", len))
		status = ft_cd(argument, environ);
	else if (!ft_strncmp(command, "echo", len))
		status = ft_echo(argument);
	else if (!ft_strncmp(command, "env", len))
		status = ft_env(argument, environ);
	else if (!ft_strncmp(command, "exit", len))
		status = ft_exit(argument, g_status);
	else if (!ft_strncmp(command, "export", len))
		status = ft_export(argument, environ);
	else if (!ft_strncmp(command, "pwd", len))
		status = ft_pwd();
	else if (!ft_strncmp(command, "unset", len))
		status = ft_unset(argument, environ);
	else
		status = ENOCOMD;
	return (status);
}
