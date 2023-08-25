/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:25:44 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 15:36:43 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

int	exception_handler(int status, char *arg_str)
{
	print_error_msg(status, arg_str);
	g_status = status;
	return (status);
}
