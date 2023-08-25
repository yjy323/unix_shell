/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:47:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 18:13:13 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	initialize(char **environment);

void	initialize(char **environment)
{
	set_tty();
	initialize_shell_signals(0);
	set_sh_variable(environment);
}
