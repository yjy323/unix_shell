/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:58:41 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 20:44:53 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h>

#include "status.h"

int	undo_redirect(char *curr_cmd, int save_stdin_fd, int save_stdout_fd)
{
	if (dup2(save_stdin_fd, STDIN_FILENO) == -1
		|| dup2(save_stdout_fd, STDOUT_FILENO) == -1
		|| close(save_stdin_fd) == -1
		|| close(save_stdout_fd) == -1)
		return (exception_handler(EGENRAL, curr_cmd, 0, 0));
	else
		return (SUCCESS);
}
