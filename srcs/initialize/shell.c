/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:32:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 18:14:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"
#include "utils.h"

void	set_sh_variable(char **environment)
{
	init_sh_variable();
	g_sh_variable.mwd = getcwd(0, 0);
	g_sh_variable.wtd = ft_xstrjoin(g_sh_variable.mwd, "/tmp/");
	g_sh_variable.environment = create_environmet_variable(environment);
}
