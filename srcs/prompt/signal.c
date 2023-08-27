/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:16:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 19:41:07 by jy_23            ###   ########.fr       */
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
static void	initialize_shell_signals_heredoc(void);

void	initialize_shell_signals(int process_level)
{
	if (process_level == 0)
		initialize_shell_signals_rl();
	else if (process_level == 1)
		initialize_shell_signals_root();
	else if (process_level == 2)
		initialize_shell_signals_child();
	else
		initialize_shell_signals_heredoc();
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
	set_signal_handler(SIGINT, signal_sighandler_child);
	set_signal_handler(SIGQUIT, signal_sighandler_child);
}

static void	initialize_shell_signals_heredoc(void)
{
	set_signal_handler(SIGINT, sigint_sighandler_heredoc);
	set_signal_handler(SIGQUIT, SIG_IGN);
}
