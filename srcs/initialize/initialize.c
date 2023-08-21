/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:47:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:00:06 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	initialize(void)
{
	set_tty();
	initialize_shell_signals();
}
