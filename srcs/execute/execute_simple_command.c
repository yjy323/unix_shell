/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:52:23 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:57:27 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "minishell.h"
#include "execute.h"
#include "status.h"
#include "expand/expand.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"

int					execute_simple_command(t_command *command,
						int pipe_in_fd, int pipe_out_fd);
static int			save_standard_fd(char *curr_cmd,
						int *p_save_stdin_fd, int *p_save_stdout_fd);
static t_word_list	*update_expanded_words(t_word_list *words);
static char			*get_curr_cmd(t_word_list *list);

int	execute_simple_command(t_command *command, int pipe_in_fd, int pipe_out_fd)
{
	int		save_stdin_fd;
	int		save_stdout_fd;
	int		status;
	char	*curr_cmd;

	command->simple->words = update_expanded_words(command->simple->words);
	curr_cmd = get_curr_cmd(command->simple->words);
	if (!curr_cmd)
		return (SUCCESS);
	if (do_pipe_redirect(curr_cmd, &pipe_in_fd, &pipe_out_fd)
		|| save_standard_fd(curr_cmd, &save_stdin_fd, &save_stdout_fd)
		|| do_redirect(command->simple->redirects, curr_cmd))
		return (EGENRAL);
	status = execute_buitin(command->simple->words);
	if (status == NOTBUILTIN)
		status = execute_filesystem(command->simple->words, curr_cmd);
	if (undo_redirect(command->simple->redirects
			, curr_cmd, save_stdin_fd, save_stdout_fd))
		return (EGENRAL);
	return (status);
}

static int	save_standard_fd(char *curr_cmd,
				int *p_save_stdin_fd, int *p_save_stdout_fd)
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

static char	*get_curr_cmd(t_word_list *list)
{
	if (!list || !list->word || !list->word->word)
		return (0);
	else
		return (list->word->word);
}
