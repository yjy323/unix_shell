/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:50:50 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/02 13:46:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include <readline/readline.h>
#include <readline/history.h>

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
	// t_command	command;

	(void)environ;
	while (1)
	{
		// open_subshell
		// read
		// parse
		// execute
	}
}