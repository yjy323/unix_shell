/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:50:50 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:29:53 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include <termios.h>
#include <term.h>

int		main(int argc, char *args[], char **environ);
void	reader_loop(char **environ);

int	main(int argc, char *args[], char **environ)
{
	(void)argc;
	(void)args;
	
	initialize();
	reader_loop(environ);
	return (0);
}

void	reader_loop(char **environ)
{
	char	*str;
	t_command	*command;

	(void)environ;
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
		// execute
		free(str);
		if (command)
			free_command(command);
	}
}
