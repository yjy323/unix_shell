/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler_sub_ps.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 05:33:32 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 15:36:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "status.h"

void	exception_handler_sub_ps(int status, char *arg_str);

void	exception_handler_sub_ps(int status, char *arg_str)
{
	print_error_msg(status, arg_str);
	g_status = status;
	exit(g_status);
}
