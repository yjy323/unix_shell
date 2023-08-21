/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:08:09 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/21 20:41:13 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN
# define BUILT_IN

# include "command.h"
# include "hashlib.h"
# include "variables.h"

int	ft_cd(t_word_list *list, t_environment *environ);
int	ft_echo(void);
int	ft_env(t_word_list *list);
int	ft_exit(t_word_list *list, int status);
int	ft_export(void);
int	ft_pwd(void);
int	ft_unset(void);

#endif
