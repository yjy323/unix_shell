/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:34:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/26 19:39:39 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"

void	init_sh_variable(void);

void	init_sh_variable(void)
{
	g_sh_variable.environment = 0;
	g_sh_variable.temp_dir_path = 0;
	g_sh_variable.status = 0;
}
