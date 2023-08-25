/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:52:23 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 21:31:07 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
#include "status.h"

int					execute_simple_command(t_command *command, char *curr_cmd, int pipe_in_fd, int pipe_out_fd);
static int			save_standard_fd(char *curr_cmd, int *p_save_stdin_fd, int *p_save_stdout_fd);
static t_word_list	*update_expanded_words(t_word_list *words);

int	execute_simple_command(t_command *command, char *curr_cmd, int pipe_in_fd, int pipe_out_fd)
{
	int	save_stdin_fd;
	int	save_stdout_fd;
	int	status;

	command->simple->words = update_expanded_words(command->simple->words);
	if (do_pipe_redirect(curr_cmd, &pipe_in_fd, &pipe_out_fd)
		|| save_standard_fd(curr_cmd, &save_stdin_fd, &save_stdout_fd)
		|| do_redirect(curr_cmd, command->simple->redirects))
		return (EGENRAL);
	status = execute_buitin(command->simple->words);
	if (status == ENOCMD)
		status = execute_filesystem(command->simple->words, curr_cmd);
	if (undo_redirect(curr_cmd, save_stdin_fd, save_stdout_fd))
		return (EGENRAL);
	return (status);
}

static int	save_standard_fd(char *curr_cmd, int *p_save_stdin_fd, int *p_save_stdout_fd)
{
	*p_save_stdin_fd = dup(STDIN_FILENO);
	*p_save_stdout_fd = dup(STDOUT_FILENO);
	if (*p_save_stdin_fd == -1
		|| *p_save_stdout_fd == -1)
		return (exception_handler(EGENRAL, curr_cmd, 0, 0));
	return (SUCCESS);
}

static t_word_list	*update_expanded_words(t_word_list *words)
{
	t_word_list	*expanded_words;

	expanded_words = expand_words(words);
	free_word_list(words);
	return (expanded_words);
}
