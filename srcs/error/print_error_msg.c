/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:26:10 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/26 20:26:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "status.h"

#include "libft.h"

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
