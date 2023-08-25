/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_connection_command.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:12:59 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 17:12:25 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"

int			execute_connection_command(t_command *command, char *curr_cmd, int pre_in, int pre_out);
static void	make_pram_pipe_fd(int *param_fd, int in_fd, int out_fd);
static int	close_pipe_fd(int in_fd, int out_fd);
static int	execute_subprocess(t_command *command, char *curr_cmd, int *io_fd, int unused_fd);

int			execute_connection_command(t_command *command, char *curr_cmd, int pre_in, int pre_out)
{
	int	pipe_fd[2];
	int	io_fd[2];
	int	pids[2];
	int	idx;
	int	status;

	pipe(pipe_fd);
	if (pipe_fd[0] == -1 || pipe_fd[1] == -1)
		return (exception_handler(EGENRAL, "|"));
	make_pram_pipe_fd(io_fd, pre_in, pipe_fd[1]);
	pids[0] = execute_subprocess(command->connection->first, curr_cmd, io_fd, pipe_fd[0]);
	make_pram_pipe_fd(io_fd, pipe_fd[0], pre_out);
	pids[1] = execute_subprocess(command->connection->second, curr_cmd, io_fd, -1);
	idx = 0;
	while (idx < 2)
	{
		waitpid(pids[idx++], &status, 0);
		status = WEXITSTATUS(status);
	}
	if (pre_out != -1)
		exit(status);
	else
		return (status);
}

static void	make_pram_pipe_fd(int *param_fd, int in_fd, int out_fd)
{
	param_fd[0] = in_fd;
	param_fd[1] = out_fd;
}

static int	execute_subprocess(t_command *command, char *curr_cmd, int *io_fd, int unused_fd)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		if (unused_fd != -1 && close(unused_fd) == -1)
			exception_handler_sub_ps(EGENRAL, curr_cmd);
		status = execute_command_internal(command, io_fd[0], io_fd[1]);
		exit(status);
	}
	else
		close_pipe_fd(io_fd[0], io_fd[1]);
	return (pid);
}

static int	close_pipe_fd(int in_fd, int out_fd)
{
	if (in_fd != -1 && close(in_fd) == -1)
		return (exception_handler(EGENRAL, "|"));
	if (out_fd != -1 && close(out_fd) == -1)
		return (exception_handler(EGENRAL, "|"));
	return (SUCCESS);
}
