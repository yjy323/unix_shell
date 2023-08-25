/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sh_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:35:16 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 18:17:01 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "variables.h"

void	clear_sh_variable();

void	clear_sh_variable()
{
	if (g_sh_variable.environment)
		free(g_sh_variable.environment);
	if (g_sh_variable.mwd)
		free(g_sh_variable.mwd);
	if (g_sh_variable.wtd)
		free(g_sh_variable.wtd);
}
