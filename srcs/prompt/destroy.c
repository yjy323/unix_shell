/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:45:59 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/04 17:24:00 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "prompt.h"
#include "variables.h"

void		destroy(void);
static void	check_leaks(void);

static void	check_leaks(void)
{
	return ;
	system("leaks minishell");
}

void	destroy(void)
{
	clear_tmp(g_sh_variable.temp_dir_path);
	clear_sh_variable();
	atexit(check_leaks);
}
