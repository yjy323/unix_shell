/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shtty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:41:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/22 15:56:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>

void	set_tty(void)
{
	struct termios	tty;

	if (tcgetattr(STDIN_FILENO, &tty) == -1)
		exit(1);
	tty.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &tty) == -1)
		exit(1);
}
