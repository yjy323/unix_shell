/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:34:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 20:07:06 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"

void	init_sh_variable();

void	init_sh_variable()
{
	g_sh_variable.environment = 0;
	g_sh_variable.temp_dir_path = 0;
	g_sh_variable.status = 0;
}
