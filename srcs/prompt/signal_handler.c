/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:00:37 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/28 15:28:58 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>

#include "libft.h"

#include "minishell.h"
#include "status.h"
#include "unistd.h"
#include "utils.h"

void	*set_signal_handler(int sig, void (*handler)(int signo));
void	sigint_sighandler(int signo);
void	signal_sighandler_child(int signo);
void	sigint_sighandler_heredoc(int signo);

void	*set_signal_handler(int sig, void (*handler)(int signo))
{
	struct sigaction	act;
	struct sigaction	oact;

	act.sa_handler = handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigemptyset(&oact.sa_mask);
	if (sigaction(sig, &act, &oact) == 0)
		return (oact.sa_handler);
	else
		return (SIG_DFL);
}

void	sigint_sighandler(int signo)
{
	(void)signo;
	g_sh_variable.status = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_sighandler_child(int signo)
{
	char	*str_ecode;

	str_ecode = ft_xitoa(ESIGNAL + signo);
	if (signo == SIGQUIT)
	{
		write(2, "QUIT: ", 6);
		write(2, str_ecode, ft_strlen(str_ecode));
		write(2, "\n", 1);
	}
	free(str_ecode);
}

void	sigint_sighandler_heredoc(int signo)
{
	(void)signo;
	g_sh_variable.status = 1;
	printf("\n");
	exit(1);
}
