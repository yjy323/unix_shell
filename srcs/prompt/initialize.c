/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:47:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 17:01:49 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	initialize(char **environment);

void	initialize(char **environment)
{
	set_tty();
	initialize_shell_signals(0);
	set_sh_variable(environment);
}
