/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:50:40 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/21 20:35:42 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	
	// set_sig
	reader_loop(environment);
	return (0);
}

void	reader_loop(char **initial_environ)
{
	char		*str;
	t_command	*command;
	t_environment *environ;

	environ = create_environmet_variable(initial_environ);

	while (1)
	{
		// open_subshell
		// read
		str = readline("minshell-3.2$ ");
		// parse
		command = parse(str);
		execute_command(command, environ);

		free(str);
		//free_command(command, environ);
	}
}

