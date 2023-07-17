/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:39:33 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 19:08:49 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include <errno.h>
# include "type.h"

# define ERROR -1

void	set_ipc(t_node *node, t_cmd *cmd);
void	operator_main_process(t_node *parent_node, t_cmd *cmd);
void	operator_sub_process(t_node *parent_node, t_cmd *cmd);

void	pipe_main_process(t_cmd *cmd);
void	pipe_sub_process(t_cmd *cmd);

void	crash(int errnum);
#endif
