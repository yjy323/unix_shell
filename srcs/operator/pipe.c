/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:42:52 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 20:14:01 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		pipe_main_process(t_cmd *cmd);
void		pipe_sub_process(t_cmd *cmd);
static void	close_unused_pipe(
				int *fd, int *pre_fd, bool is_first, bool is_last);
static void	redirect_pipe(int *fd, int *pre_fd, bool is_first, bool is_last);

void	pipe_main_process(t_cmd *cmd)
{
	close_unused_pipe(
		cmd->fd, cmd->pre_fd, cmd->flag_first_cmd, cmd->flag_last_cmd);
	cmd->pre_fd[0] = cmd->fd[0];
	cmd->pre_fd[1] = cmd->fd[1];
}

void	pipe_sub_process(t_cmd *cmd)
{
	redirect_pipe(
		cmd->fd, cmd->pre_fd, cmd->flag_first_cmd, cmd->flag_last_cmd);
}

static void	close_unused_pipe(int *fd, int *pre_fd, bool is_first, bool is_last)
{
	if (is_first == true)
	{
		if (close(fd[1]) == ERROR)
			crash("Close pipe", errno);
	}
	else if (is_last == true)
	{
		if (close(pre_fd[0]) == ERROR)
			crash("Close pipe", errno);
	}
	else
	{
		if (close(fd[1]) == ERROR
			|| close(pre_fd[0]) == ERROR)
			crash("Close pipe", errno);
	}
}

static void	redirect_pipe(int *fd, int *pre_fd, bool is_first, bool is_last)
{
	if (is_first == true)
	{
		if (close(fd[0]) == ERROR
			|| dup2(fd[1], STDOUT_FILENO) == ERROR)
			crash("Redirection pipe", errno);
	}
	else if (is_last == true)
	{
		if (dup2(pre_fd[0], STDIN_FILENO) == ERROR)
			crash("Redirection pipe", errno);
	}
	else
	{
		if (close(fd[0]) == ERROR
			|| dup2(pre_fd[0], STDIN_FILENO) == ERROR
			|| dup2(fd[1], STDOUT_FILENO) == ERROR)
			crash("Redirection pipe", errno);
	}
}
