/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:25:44 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 03:26:22 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

extern int	g_status;

int	exception_handler(int status, char *arg_str)
{
	print_error_msg(status, arg_str);
	g_status = status;
	return (status);
}
