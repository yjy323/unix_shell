/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:50:40 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 14:59:49 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	g_status;

int			main(int argc, char *args[], char **environment);
static void	reader_loop(t_sh_variable *sh_variable);
static char	*sh_readline(void);

int	main(int argc, char *args[], char **environment)
{
	t_sh_variable	sh_variable;
	
	(void)argc;
	(void)args;
	initialize(&sh_variable, environment);
	reader_loop(&sh_variable);
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
		execute_command(command, sh_variable->environment);
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