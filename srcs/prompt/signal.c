/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:16:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 17:01:49 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>

#include "prompt.h"

void		initialize_shell_signals(int process_level);
static void	initialize_shell_signals_rl(void);
static void	initialize_shell_signals_root(void);
static void	initialize_shell_signals_child(void);
static void	*set_signal_handler(int sig, void (*handler)(int signo));

void	initialize_shell_signals(int process_level)
{
	if (process_level == 0)
		initialize_shell_signals_rl();
	else if (process_level == 1)
		initialize_shell_signals_root();
	else
		initialize_shell_signals_child();
}

static void	initialize_shell_signals_rl(void)
{
	set_signal_handler(SIGINT, sigint_sighandler);
	set_signal_handler(SIGQUIT, SIG_IGN);
}

static void	initialize_shell_signals_root(void)
{
	set_signal_handler(SIGINT, SIG_IGN);
	set_signal_handler(SIGQUIT, SIG_IGN);
}

static void	initialize_shell_signals_child(void)
{
	set_signal_handler(SIGINT, sigint_sighandler_heredoc);
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
