/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:32:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 20:06:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "minishell.h"
#include "variables.h"
#include "utils.h"

void	set_sh_variable(char **environment)
{
	char	*home_dir_path;

	init_sh_variable();
	home_dir_path = getcwd(0, 0);
	g_sh_variable.temp_dir_path = ft_xstrjoin(home_dir_path, "/tmp/");
	g_sh_variable.environment = create_environmet_variable(environment);
	free(home_dir_path);
}
