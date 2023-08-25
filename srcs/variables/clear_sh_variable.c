/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sh_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:35:16 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 21:05:43 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "variables.h"

void	clear_sh_variable(void);

void	clear_sh_variable(void)
{
	if (g_sh_variable.environment)
		free(g_sh_variable.environment);
	if (g_sh_variable.temp_dir_path)
		free(g_sh_variable.temp_dir_path);
}
