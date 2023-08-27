/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:15:59 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 18:28:16 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "command.h"
# include "builtin.h"
# include "variables.h"

# define ERROR -1
# define ENOCMD 127

typedef enum e_redir_flag{
	redir_err,
	redir_in,
	redir_out,
	redir_out_append,
	redir_here_doc
}	t_redir_flag;

int				execute_command(t_command *command);
int				execute_command_internal(t_command *command,
					int pre_in, int pre_out);
int				execute_connection_command(t_command *command,
					int pre_in, int pre_out);
int				execute_simple_command(t_command *command,
					int pipe_in_fd, int pipe_out_fd);
int				execute_buitin(t_word_list *words);
int				execute_filesystem(t_word_list *words, char *curr_cmd);

int				do_redirect(t_redirect_list *redirects, char *curr_cmd);
int				undo_redirect(t_redirect_list *redirects,
					char *curr_cmd, int save_stdin_fd, int save_stdout_fd);
t_redir_flag	get_redir_flag(char *redirector);
int				do_pipe_redirect(char *curr_cmd,
					int *p_pipe_in_fd, int *p_pipe_out_fd);

int				job_control(int pid);

#endif
