/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/24 17:47:15 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/minishell.h"

int	g_status;

void	crash(char *message, int errnum)
{
	perror(message);
	exit(errnum);
}

int	main(int argc, char *args[], char **environ)
{
	t_tree	ast;
	char	*str;

	(void)argc;
	(void)args;
	str = readline("readline input : ");
	ast.root = 0;
	parse(str, &ast);
	free(str);
	execute(ast.root, &environ);
	return (0);
}
