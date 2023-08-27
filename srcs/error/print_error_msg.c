/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:26:10 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:54:25 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "libft.h"

#include "status.h"

void	print_error_msg(int status, char *cmd, char *arg, char *msg);

void	print_error_msg(int status, char *cmd, char *arg, char *msg)
{
	write(2, "minishell: ", 11);
	if (status == ESYNTEX)
		write(2, MSYNTAX, ft_strlen(MSYNTAX));
	if (cmd)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
	}
	if (arg)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": ", 2);
	}
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	else
		perror("");
}
