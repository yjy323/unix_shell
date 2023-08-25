/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:10:49 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 20:51:09 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <fcntl.h>
#include <unistd.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"

#include "libft.h"

int			do_redirect(char *curr_cmd, t_redirect_list *redirects);
static int	do_redirect_stdin(char *curr_cmd, char *file, char *redir);
static int	do_redirect_stdout(char *curr_cmd, char *file);
static int	do_redirect_stdout_append(char *curr_cmd, char *file);

int	do_redirect(char *curr_cmd, t_redirect_list *redirects)
{
	t_redirect_list	*iter;
	char			*operator;
	char			*file;
	int				status;

	iter = redirects;
	status = SUCCESS;
	while (iter)
	{
		operator = iter->redirect->word;
		file = iter->redirect->filename;
		if (ft_strlen(operator) == 1)
		{
			if (*operator == '<')
				status = do_redirect_stdin(curr_cmd, file, "<");
			else if (*operator == '>')
				status = do_redirect_stdout(curr_cmd, file);
		}
		else if (ft_strlen(operator) == 2)
		{
			if (*operator == '<' && *(operator + 1) == '<')
				status = do_redirect_stdin(curr_cmd, file, "<<");
			else if (*operator == '>' && *(operator + 1) == '>')
				status = do_redirect_stdout_append(curr_cmd, file);
		}
		iter = iter->next;
	}
	return (status);
}

static int	do_redirect_stdin(char *curr_cmd, char *file, char *redir)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, curr_cmd, redir, 0));
	if (dup2(fd, STDIN_FILENO) == -1)
		return (exception_handler(EGENRAL, curr_cmd, redir, 0));
	return (SUCCESS);
}

static int	do_redirect_stdout(char *curr_cmd, char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, curr_cmd, ">", 0));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (exception_handler(EGENRAL, curr_cmd, ">", 0));
	return (SUCCESS);
}

static int	do_redirect_stdout_append(char *curr_cmd, char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, curr_cmd, ">>", 0));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (exception_handler(EGENRAL, curr_cmd, ">>", 0));
	return (SUCCESS);
}
