/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_connection_command.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:12:59 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/21 20:59:04 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "execute.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"

extern int	g_status;

int			execute_connection_command(t_command *command, t_environment *environ, int pre_in, int pre_out);
static void	make_pram_pipe_fd(int *param_fd, int in_fd, int out_fd);
static void	close_pipe_fd(int in_fd, int out_fd);
static int	execute_subprocess(t_command *command, t_environment *environ, int *io_fd, int unused_fd);

//  구조 리팩토링 여부 결정 필요
int	execute_connection_command(t_command *command, t_environment *environ, int pre_in, int pre_out)
{
	int	pipe_fd[2];
	int	param_pipe_fd[2];
	int	pids[2];
	int	idx;
	int	status;

	pipe(pipe_fd);
	make_pram_pipe_fd(param_pipe_fd, pre_in, pipe_fd[1]);
	pids[0] = execute_subprocess(command->connection->first, environ, param_pipe_fd, pipe_fd[0]);
	make_pram_pipe_fd(param_pipe_fd, pipe_fd[0], pre_out);
	pids[1] = execute_subprocess(command->connection->second, environ, param_pipe_fd, pipe_fd[1]);
	idx = 0;
	while (idx < 2)
	{
		waitpid(pids[idx++], &status, 0);
		g_status = WEXITSTATUS(status);
	}
	if (pre_out != -1)
		exit(g_status);
	else
		return (g_status);
}

static void	make_pram_pipe_fd(int *param_fd, int in_fd, int out_fd)
{
	param_fd[0] = in_fd;
	param_fd[1] = out_fd;
}

static void	close_pipe_fd(int in_fd, int out_fd)
{
	if (in_fd != -1)
		close(in_fd);
	if (out_fd != -1)
		close(out_fd);
}

static int	execute_subprocess(t_command *command, t_environment *environ, int *io_fd, int unused_fd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (unused_fd != -1)
			close(unused_fd);
		g_status = execute_command_internal(command, environ, io_fd[0], io_fd[1]);
		exit(g_status);
	}
	else
		close_pipe_fd(io_fd[0], io_fd[1]);
	return (pid);
}
