/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 03:21:03 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 17:00:12 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>

#include "status.h"

void	crash(int status, char *arg_str)
{
	print_error_msg(status, arg_str);
	g_sh_variable.status = status;
	exit(status);
}
