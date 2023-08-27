/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:32:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 21:00:23 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"
#include "variables.h"
#include "utils.h"

void	set_sh_variable(char **environment)
{
	char	*home_dir_path;

	init_sh_variable();
	home_dir_path = getcwd(0, 0);
	g_sh_variable.temp_dir_path = ft_xstrjoin(home_dir_path, "/tmp/");
	g_sh_variable.environment = create_environment_variable(environment);
	free(home_dir_path);
}

char	*sh_readline(void)
{
	char	*str;

	str = readline("minishell-1.0$ ");
	if (rl_eof_found)
	{
		printf("exit\n");
		return (0);
	}
	add_history(str);
	return (str);
}
