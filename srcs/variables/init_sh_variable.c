/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:34:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 16:55:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

void	init_sh_variable(t_sh_variable *sh_variable);

void	init_sh_variable(t_sh_variable *sh_variable)
{
	sh_variable->environment = 0;
	sh_variable->mwd = 0;
	sh_variable->wtd = 0;
}