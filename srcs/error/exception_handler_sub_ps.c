/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler_sub_ps.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 05:33:32 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 17:29:33 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>

#include "status.h"

void	exception_handler_sub_ps(int status, char *arg_str);

void	exception_handler_sub_ps(int status, char *arg_str)
{
	print_error_msg(status, arg_str);
	g_sh_variable.status = status;
	exit(status);
}
