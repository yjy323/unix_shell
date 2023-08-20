/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:16:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 14:32:47 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>

void		initialize_shell_signals(void);
static void	*set_signal_handler(int sig, void (*handler)(int signo));
static void	sigint_sighandler(int signo);

void	initialize_shell_signals(void)
{
	set_signal_handler(SIGINT, sigint_sighandler);
	set_signal_handler(SIGQUIT, SIG_IGN);
}

static void	*set_signal_handler(int sig, void (*handler)(int signo))
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

static void	sigint_sighandler(int signo)
{
	(void)signo;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
