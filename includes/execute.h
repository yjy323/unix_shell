/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:59:04 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 20:03:43 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

# include "type.h"
# include "builtin.h"
# include "operator.h"

void	execute(t_node *node, t_cmd *cmd);

char	**set_cmd_args(t_node *node);
char	*set_cmd_path(char *cmd, char **path);
void	redirect(t_node *node, int fd_stdout);

void	wait_handler(t_cmd *cmd, t_type type, int pid);
void	wait_all_remain_process(t_pid_list *sub_pid_head);

bool	is_single_command(t_node *head);
bool	is_last_command(t_node *head);
bool	is_sequential_cmd(t_type type);
bool	is_asynchronous_cmd(t_type type);
bool	is_builtin(char *cmd_name);

t_cmd	*init_cmd(char *envp[]);
#endif
