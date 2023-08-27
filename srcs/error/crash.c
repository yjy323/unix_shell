/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 03:21:03 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:54:06 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "status.h"

void	crash(int status, char *cmd, char *arg, char *msg);

void	crash(int status, char *cmd, char *arg, char *msg)
{
	print_error_msg(status, cmd, arg, msg);
	g_sh_variable.status = status;
	exit(status);
}
