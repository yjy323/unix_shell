/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:39:33 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 17:10:47 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include <stdbool.h>

# include "../common.h"
# include "type_execute.h"

void	operate_pipe(t_node *command_node, t_compound *comp_exec);
void	operate_single_command(t_node *command_node, t_compound *comp_exec);

void	sub_process_wait(t_pid_lst *head);
void	sub_process_add_lst(t_pid_lst *head, int pid);

bool	is_first_operate_cmd(t_node *command_node, t_type type);
bool	is_last_operate_cmd(t_node *command_node, t_type type);

#endif
