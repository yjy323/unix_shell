/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:25:44 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 21:21:03 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "status.h"

int	exception_handler(int status, char *cmd, char *arg, char *msg)
{
	print_error_msg(status, cmd, arg, msg);
	g_sh_variable.status = status;
	return (status);
}
