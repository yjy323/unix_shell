/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:42:09 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/26 18:53:40 by jy_23            ###   ########.fr       */
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
	int			len;
	char		*command;
	t_word_list	*argument;

	command = words->word->word;
	argument = words->next;
	len = ft_strlen(command);
	if (!ft_strncmp(command, "cd", len + 1))
		g_sh_variable.status = ft_cd(argument);
	else if (!ft_strncmp(command, "echo", len + 1))
		g_sh_variable.status = ft_echo(argument);
	else if (!ft_strncmp(command, "env", len + 1))
		g_sh_variable.status = ft_env(argument);
	else if (!ft_strncmp(command, "exit", len + 1))
		g_sh_variable.status = ft_exit(argument);
	else if (!ft_strncmp(command, "export", len + 1))
		g_sh_variable.status = ft_export(argument);
	else if (!ft_strncmp(command, "pwd", len + 1))
		g_sh_variable.status = ft_pwd();
	else if (!ft_strncmp(command, "unset", len + 1))
		g_sh_variable.status = ft_unset(argument);
	else
		return (NOTBUILTIN);
	return (g_sh_variable.status);
}
