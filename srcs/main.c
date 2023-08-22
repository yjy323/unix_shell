/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:50:40 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/21 21:15:15 by jy_23            ###   ########.fr       */
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
#include "minishell.h"
#include "variables.h"
#include "execute.h"

int	g_status;

int		main(int argc, char *args[], char **environment);
void	reader_loop(char **environ);

int	main(int argc, char *args[], char **environment)
{
	(void)argc;
	(void)args;
	
	initialize();
	reader_loop(environment);
	return (0);
}

void	reader_loop(char **initial_environ)
{
	char	*str;
	t_command	*command;
	t_environment *environ;

	environ = create_environmet_variable(initial_environ);

	while (1)
	{
		// read
		str = readline("minshell-3.2$ ");
		if (rl_eof_found)
		{
			printf("exit\n");
			exit(0);
		}
		add_history(str);
		// parse
		command = parse(str);
		execute_command(command, environ);
		free(str);
		if (command)
			free_command(command);
	}
}

