/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:51:46 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/14 19:32:21 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	// if (pwd == 0)
	//	 return (1)
	printf("%s\n", pwd);
	free(pwd);
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
