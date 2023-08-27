/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:42:09 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:56:17 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "minishell.h"
#include "status.h"
#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"

int	execute_buitin(t_word_list *words);

int	execute_buitin(t_word_list *words)
{
	int			len;
	char		*command;
	t_word_list	*argument;
	int			status;

	command = words->word->word;
	argument = words->next;
	len = ft_strlen(command);
	if (!ft_strncmp(command, "cd", len + 1))
		status = ft_cd(argument);
	else if (!ft_strncmp(command, "echo", len + 1))
		status = ft_echo(argument);
	else if (!ft_strncmp(command, "env", len + 1))
		status = ft_env(argument);
	else if (!ft_strncmp(command, "exit", len + 1))
		status = ft_exit(argument);
	else if (!ft_strncmp(command, "export", len + 1))
		status = ft_export(argument);
	else if (!ft_strncmp(command, "pwd", len + 1))
		status = ft_pwd();
	else if (!ft_strncmp(command, "unset", len + 1))
		status = ft_unset(argument);
	else
		return (NOTBUILTIN);
	return (status);
}
