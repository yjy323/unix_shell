/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:49:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 13:12:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "variables.h"

void	initialize(t_sh_variable *sh_variable, char **environment);
void	initialize_shell_signals(int process_level);
void	set_tty(void);
void	set_sh_variable(t_sh_variable *sh_variable, char **environment);

#endif
