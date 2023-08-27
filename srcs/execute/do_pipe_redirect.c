/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:12:08 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:54:39 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "status.h"

int	do_pipe_redirect(char *curr_cmd, int *p_pipe_in_fd, int *p_pipe_out_fd)
{
	if (*p_pipe_in_fd != -1 && dup2(*p_pipe_in_fd, STDIN_FILENO) == -1)
		return (exception_handler(EGENRAL, curr_cmd, "|", 0));
	if (*p_pipe_out_fd != -1 && dup2(*p_pipe_out_fd, STDOUT_FILENO) == -1)
		return (exception_handler(EGENRAL, curr_cmd, "|", 0));
	return (SUCCESS);
}
