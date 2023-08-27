/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:10:49 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:54:54 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

#include "minishell.h"
#include "execute.h"
#include "status.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"

int			do_redirect(t_redirect_list *redirects, char *curr_cmd);
static int	do_redirect_stdin(t_redirect *redir, char *curr_cmd);
static int	do_redirect_stdout(t_redirect *redir, char *curr_cmd);
static int	do_redirect_stdout_append(t_redirect *redir, char *curr_cmd);

int	do_redirect(t_redirect_list *redirects, char *curr_cmd)
{
	t_redirect_list	*iter;
	t_redirect		*redir;
	int				status;
	t_redir_flag	redir_flag;

	iter = redirects;
	status = SUCCESS;
	while (iter)
	{
		redir = iter->redirect;
		redir_flag = get_redir_flag(redir->word);
		if (redir_flag == redir_in)
			status = do_redirect_stdin(redir, curr_cmd);
		else if (redir_flag == redir_out)
			status = do_redirect_stdout(redir, curr_cmd);
		else if (redir_flag == redir_here_doc)
			status = do_redirect_stdin(redir, curr_cmd);
		else if (redir_flag == redir_out_append)
			status = do_redirect_stdout_append(redir, curr_cmd);
		iter = iter->next;
	}
	return (status);
}

static int	do_redirect_stdin(t_redirect *redir, char *curr_cmd)
{
	int	fd;

	fd = open(redir->filename, O_RDONLY, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, curr_cmd, redir->word, 0));
	redir->fd = fd;
	if (dup2(fd, STDIN_FILENO) == -1)
		return (exception_handler(EGENRAL, curr_cmd, redir->word, 0));
	return (SUCCESS);
}

static int	do_redirect_stdout(t_redirect *redir, char *curr_cmd)
{
	int	fd;

	fd = open(redir->filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, curr_cmd, redir->word, 0));
	redir->fd = fd;
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (exception_handler(EGENRAL, curr_cmd, redir->word, 0));
	return (SUCCESS);
}

static int	do_redirect_stdout_append(t_redirect *redir, char *curr_cmd)
{
	int	fd;

	fd = open(redir->filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, curr_cmd, redir->word, 0));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (exception_handler(EGENRAL, curr_cmd, redir->word, 0));
	return (SUCCESS);
}
