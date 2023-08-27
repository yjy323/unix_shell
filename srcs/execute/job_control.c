/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:22:24 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:57:53 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>

#include "minishell.h"
#include "prompt.h"

int			job_control(int pid);

int	job_control(int pid)
{
	int	status;
	int	status_exit;
	int	status_sig;

	waitpid(pid, &status, 0);
	status_exit = WEXITSTATUS(status);
	status_sig = WTERMSIG(status);
	if (status_sig)
		signal_sighandler_child(status_sig);
	return (status_exit + status_sig);
}
