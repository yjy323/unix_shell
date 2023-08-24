/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:29:40 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 13:37:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "command.h"
# include "variables.h"

# define SH_NAME "minishell"

void		initialize(void);
t_command	*parse(char *str, t_sh_variable *sh_variable);

#endif
