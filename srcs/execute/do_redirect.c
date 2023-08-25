/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:10:49 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 06:29:28 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"

#include "libft.h"

int			do_redirect(t_redirect_list *redirects);
static int	do_redirect_stdin(char *file);
static int	do_redirect_stdout(char *file);
static int	do_redirect_stdout_append(char *file);

int	do_redirect(t_redirect_list *redirects)
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
				status = do_redirect_stdin(file);
			else if (*operator == '>')
				status = do_redirect_stdout(file);
		}
		else if (ft_strlen(operator) == 2)
		{
			if (*operator == '<' && *(operator + 1) == '<')
				status = do_redirect_stdin(file);
			else if (*operator == '>' && *(operator + 1) == '>')
				status = do_redirect_stdout_append(file);
		}
		iter = iter->next;
	}
	return (status);
}

static int	do_redirect_stdin(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, file));
	if (dup2(fd, STDIN_FILENO) == -1)
		return (exception_handler(EGENRAL, file));
	return (SUCCESS);
}

static int	do_redirect_stdout(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, file));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (exception_handler(EGENRAL, file));
	return (SUCCESS);
}

static int	do_redirect_stdout_append(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (exception_handler(EGENRAL, file));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (exception_handler(EGENRAL, file));
	return (SUCCESS);
}
