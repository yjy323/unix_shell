/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shtty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:41:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 19:46:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <term.h>

void	set_tty(void)
{
	struct termios	tty;

	if (tcgetattr(STDIN_FILENO, &tty) == -1)
		; // crash
	tty.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &tty) == -1)
		; // crash
}
