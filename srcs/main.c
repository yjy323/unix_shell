/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/20 18:54:17 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/minishell.h"

extern char	**environ;

void	crash(char *message, int errnum)
{
	perror(message);
	exit(errnum);
}

int	main(void)
{
	return (0);
}
