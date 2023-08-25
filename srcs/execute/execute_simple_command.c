/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:52:23 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 07:09:58 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"
#include "expand/expand.h"

#include "libft.h"

extern int	g_status;

int					execute_simple_command(t_command *command,
						t_environment *environ,
						int pipe_in_fd, int pipe_out_fd);
static int			save_standard_fd(int *p_save_stdin_fd,
						int *p_save_stdout_fd);
static t_word_list	*update_expanded_words(t_word_list *words,
						t_environment *environ);

int	execute_simple_command(t_command *command,
			t_environment *environ, int pipe_in_fd, int pipe_out_fd)
{
	int	save_stdin_fd;
	int	save_stdout_fd;

	command->simple->words = update_expanded_words(
			command->simple->words, environ);
	if (do_pipe_redirect(&pipe_in_fd, &pipe_out_fd)
		|| save_standard_fd(&save_stdin_fd, &save_stdout_fd)
		|| do_redirect(command->simple->redirects))
		return (g_status);
	if (execute_buitin(command->simple->words, environ) == ENOCOMD)
		g_status = execute_filesystem(command->simple->words, environ);
	if (undo_redirect(save_stdin_fd, save_stdout_fd))
		return (g_status);
	return (SUCCESS);
}

static int	save_standard_fd(int *p_save_stdin_fd, int *p_save_stdout_fd)
{
	*p_save_stdin_fd = dup(STDIN_FILENO);
	*p_save_stdout_fd = dup(STDOUT_FILENO);
	if (*p_save_stdin_fd == -1
		|| *p_save_stdout_fd == -1)
		return (exception_handler(EGENRAL, ""));
	return (SUCCESS);
}

static t_word_list	*update_expanded_words(t_word_list *words,
				t_environment *environ)
{
	t_word_list	*expanded_words;

	expanded_words = expand_words(environ, words);
	free(words);
	return (expanded_words);
}
