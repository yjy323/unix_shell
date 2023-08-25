/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:26:10 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 15:36:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "status.h"

#include "libft.h"

void		print_error_msg(int status, char *arg_str);
static void	ft_perror(char *arg_str, char *err_msg);
static void	print_error_msg_general(int status, char *arg_str);
static void	print_error_msg_missuse(int status, char *arg_str);

void	print_error_msg(int status, char *arg_str)
{
	write(2, arg_str, ft_strlen(arg_str));
	write(2, " :", 2);
	if (status == EGENRAL)
		print_error_msg_general(status, arg_str);
	else if (status == EMISUSE)
		print_error_msg_missuse(status, arg_str);
	else if (status == ENOPERM)
		ft_perror(arg_str, MNOPERM);
	else if (status == ENOCOMD)
		ft_perror(arg_str, MNOCOMD);
	else
		perror(arg_str);
}

static void	ft_perror(char *arg_str, char *err_msg)
{
	write(2, arg_str, ft_strlen(arg_str));
	write(2, " :", 2);
	write(2, err_msg, ft_strlen(arg_str));
	write(2, "\n", 1);
}

static void	print_error_msg_general(int status, char *arg_str)
{
	(void)status;
	perror(arg_str);
}

static void	print_error_msg_missuse(int status, char *arg_str)
{
	(void)status;
	perror(arg_str);
}
