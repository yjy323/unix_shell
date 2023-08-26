/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:08:09 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/26 17:14:30 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "command.h"
# include "hashlib.h"
# include "variables.h"

int	ft_cd(t_word_list *list);
int	ft_echo(t_word_list *list);
int	ft_env(t_word_list *list);
int	ft_exit(t_word_list *list);
int	ft_export(t_word_list *list);
int	ft_pwd(void);
int	ft_unset(t_word_list *list);

int	valid_environ_convention(char *cmd, char *key);

#endif
