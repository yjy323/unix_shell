/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:45:59 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/28 15:00:19 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "prompt.h"
#include "variables.h"

/* leaks check */
#include <stdlib.h>
void	check_leaks(void)
{
	system("leaks minishell");
}

void	destroy(void)
{
	clear_tmp(g_sh_variable.temp_dir_path);
	clear_sh_variable();
	
	//atexit(check_leaks);
}
