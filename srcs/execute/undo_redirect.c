/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:58:41 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:58:03 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "status.h"
#include "execute.h"

int			undo_redirect(t_redirect_list *redirects,
				char *curr_cmd, int save_stdin_fd, int save_stdout_fd);
static int	undo_std_redirect(char *curr_cmd,
				int save_stdin_fd, int save_stdout_fd);

int	undo_redirect(t_redirect_list *redirects,
		char *curr_cmd, int save_stdin_fd, int save_stdout_fd)
{
	t_redirect_list	*iter;
	t_redirect		*redir;

	if (undo_std_redirect(curr_cmd, save_stdin_fd, save_stdout_fd))
		return (EGENRAL);
	iter = redirects;
	while (iter)
	{
		redir = iter->redirect;
		if (redir->fd != -1 && close(redir->fd) == -1)
			return (exception_handler(EGENRAL, curr_cmd, redir->filename, 0));
		iter = iter->next;
	}
	return (SUCCESS);
}

static int	undo_std_redirect(char *curr_cmd,
				int save_stdin_fd, int save_stdout_fd)
{
	if (dup2(save_stdin_fd, STDIN_FILENO) == -1
		|| dup2(save_stdout_fd, STDOUT_FILENO) == -1
		|| close(save_stdin_fd) == -1
		|| close(save_stdout_fd) == -1)
		return (exception_handler(EGENRAL, curr_cmd, 0, 0));
	else
		return (SUCCESS);
}
