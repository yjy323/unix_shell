/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:49:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 17:31:10 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "variables.h"

void	initialize(char **environment);
void	destroy(void);
void	initialize_shell_signals(int process_level);
void	set_tty(void);
void	set_sh_variable(char **environment);
char	*sh_readline(void);

void	*set_signal_handler(int sig, void (*handler)(int signo));
void	sigint_sighandler(int signo);
void	signal_sighandler_child(int signo);
void	sigint_sighandler_heredoc(int signo);
int		clear_tmp(char *tmp_path);

#endif
