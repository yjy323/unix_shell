/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:22:24 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 19:07:04 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "prompt.h"

#include <unistd.h>
#include <sys/wait.h>

int			job_control(int pid);
static void	job_control_sig_handler(int sig_code);

int	job_control(int pid)
{
	int	status;
	int	status_exit;
	int	status_sig;

	waitpid(pid, &status, 0);
	status_exit = WEXITSTATUS(status);
	status_sig = WTERMSIG(status);
	if (status_sig)
		job_control_sig_handler(status_sig);
	return (status_exit + status_sig);
}

static void	job_control_sig_handler(int sig_code)
{
	signal_sighandler_child(sig_code);
}
