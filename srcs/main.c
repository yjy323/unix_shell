/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:50:40 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 21:06:02 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "prompt.h"
#include "parse/parse.h"
#include "execute.h"
#include "command.h"

int			main(int argc, char *args[], char **init_environ);
static void	reader_loop(void);

int	main(int argc, char *args[], char **init_environ)
{
	(void)argc;
	(void)args;
	initialize(init_environ);
	reader_loop();
	destroy();
	return (0);
}

static void	reader_loop(void)
{
	char		*str;
	t_command	*command;

	while (1)
	{
		initialize_shell_signals(0);
		str = sh_readline();
		initialize_shell_signals(1);
		if (!str)
			return ;
		command = parse(str);
		execute_command(command);
		clear_tmp(g_sh_variable.temp_dir_path);
		free(str);
		if (command)
			free_command(command);
	}
}
