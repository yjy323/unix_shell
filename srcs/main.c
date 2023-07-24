/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/24 17:07:15 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void)argc;
	(void)args;
	(void)environ;
	return (0);
}
