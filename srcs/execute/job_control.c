/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:22:24 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 18:29:41 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (sig_code == 0)
		write(STDERR_FILENO, "", 0);
	else if (sig_code == 1)
		write(STDERR_FILENO, "", 0);
}
