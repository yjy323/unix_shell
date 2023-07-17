/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/17 20:04:48 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern char	**environ;

int	main(void)
{
	t_tree	ast;
	t_cmd	*cmd;
	char	*str;

	str = readline("readline input : ");
	init_tree(&ast);
	parse(str, &ast);
	free(str);
	cmd = init_cmd(environ);
	execute(ast.root, cmd);
	clear_tree(&ast);
	return (0);
}
