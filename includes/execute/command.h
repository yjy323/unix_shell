/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:41:54 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 17:13:39 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "../common.h"
# include "type_execute.h"

void	exec_command(t_node *command_node, t_compound *comp_exec);
void	exec_redirect(t_node *redirect_node, int save_stdout);

#endif
