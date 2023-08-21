/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:10:49 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/21 21:08:11 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"

#include "libft.h"

int			do_redirect(t_redirect_list *redirects);
static int	do_redirect_stdin(char *operator, char *file);
static int	do_redirect_stdout(char *operator, char *file);
static int	do_redirect_stdout_append(char *operator, char *file);

int	do_redirect(t_redirect_list *redirects)
{
	t_redirect_list	*iter;
	char		*operator;
	char		*file;
	int			status;

	iter = redirects;
	while (iter)
	{
		operator = iter->redirect->word;
		file = iter->redirect->filename;
		//  check file permission
		if (ft_strlen(operator) == 1)
		{
			if (*operator == '<')
				status = do_redirect_stdin(operator, file);
			else if (*operator == '>')
				status = do_redirect_stdout(operator, file);
		}
		else if (ft_strlen(operator) == 2)
		{
			/*if (*operator == '<')
				status = do_redirect_heredoc(operator, file);
			else */ if (*operator == '>' && *(operator + 1) == '>')
				status = do_redirect_stdout_append(operator, file);
		}
		if (status != 0)
			break;
		iter = iter->next;
	}
	return (status);
}


static int	do_redirect_stdin(char *operator, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd == ERROR)
		crash(1, file);
	if (dup2(fd, STDIN_FILENO) == ERROR)
		crash(1, operator);
	return (0);
}

static int	do_redirect_stdout(char *operator, char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == ERROR)
		crash(1, file);
	if (dup2(fd, STDOUT_FILENO) == ERROR)
		crash(1, operator);
	return (0);
}

static int	do_redirect_stdout_append(char *operator, char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == ERROR)
		crash(errno, file);
	if (dup2(fd, STDOUT_FILENO) == ERROR)
		crash(errno, operator);
	return (0);
}
