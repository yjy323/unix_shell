/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:32:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 17:56:45 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"
#include "utils.h"

void	set_sh_variable(t_sh_variable *sh_variable, char **environment)
{
	init_sh_variable(sh_variable);
	sh_variable->mwd = getcwd(0, 0);
	sh_variable->wtd = ft_xstrjoin(sh_variable->mwd, "/tmp/");
	sh_variable->environment = create_environmet_variable(environment);
}