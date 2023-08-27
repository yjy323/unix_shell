/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sh_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:35:16 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 17:36:59 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "prompt.h"
#include "variables.h"

void	clear_sh_variable(void);

void	clear_sh_variable(void)
{
	clear_tmp(g_sh_variable.temp_dir_path);
	destroy_environment_variable(g_sh_variable.environment);
	if (g_sh_variable.temp_dir_path)
		free(g_sh_variable.temp_dir_path);
}
