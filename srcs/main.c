/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:50:40 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 17:36:33 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include <termios.h>
#include <term.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "variables.h"
#include "execute.h"
#include "initialize.h"
#include "parse/parse.h"


int			main(int argc, char *args[], char **environment);
static void	reader_loop(t_sh_variable *sh_variable);
static char	*sh_readline(void);

t_sh_variable	g_sh_variable;

int	main(int argc, char *args[], char **environment)
{
	(void)argc;
	(void)args;
	initialize(&g_sh_variable, environment);
	reader_loop(&g_sh_variable);
	clear_sh_variable(&g_sh_variable);
	return (0);
}

static void	reader_loop(t_sh_variable *sh_variable)
{
	char		*str;
	t_command	*command;

	while (1)
	{
		str = sh_readline();
		command = parse(str, sh_variable);
		execute_command(command);
		free(str);
		if (command)
			free_command(command);
	}
}

static char	*sh_readline(void)
{
	char	*str;

	str = readline("minshell-3.2$ ");
	if (rl_eof_found)
	{
		printf("exit\n");
		exit(0);
	}
	add_history(str);
	return (str);
}
