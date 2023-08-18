/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:50:50 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/14 19:52:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

int		main(int argc, char *args[], char **environ);
void	reader_loop(char **environ);

int	main(int argc, char *args[], char **environ)
{
	(void)argc;
	(void)args;
	
	// set_sig
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
		// open_subshell
		// read
		str = readline("minshell-3.2$ ");
		// parse
		command = parse(str);
		// execute

		free(str);
		free_command(command);
	}
}