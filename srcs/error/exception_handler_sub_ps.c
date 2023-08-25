/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler_sub_ps.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 05:33:32 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 21:19:20 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>

#include "status.h"

void	exception_handler_sub_ps(int status, char *cmd, char *arg, char *msg);

void	exception_handler_sub_ps(int status, char *cmd, char *arg, char *msg)
{
	print_error_msg(status, cmd, arg, msg);
	g_sh_variable.status = status;
	exit(status);
}
