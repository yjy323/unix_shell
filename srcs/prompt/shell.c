/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:32:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/26 17:20:55 by jy_23            ###   ########.fr       */
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
	g_sh_variable.environment = create_environment_variable(environment);
	free(home_dir_path);
}
