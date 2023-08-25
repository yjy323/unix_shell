/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:25:44 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 17:14:18 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "status.h"

int	exception_handler(int status, char *arg_str)
{
	print_error_msg(status, arg_str);
	g_sh_variable.status = status;
	return (status);
}
