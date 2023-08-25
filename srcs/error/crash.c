/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 03:21:03 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 15:36:40 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "status.h"

void	crash(int status, char *arg_str)
{
	print_error_msg(status, arg_str);
	g_status = status;
	exit(status);
}
