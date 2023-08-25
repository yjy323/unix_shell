/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:47:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 13:43:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	initialize(t_sh_variable *sh_variable, char **environment);

void	initialize(t_sh_variable *sh_variable, char **environment)
{
	set_tty();
	initialize_shell_signals(0);
	set_sh_variable(sh_variable, environment);
}
