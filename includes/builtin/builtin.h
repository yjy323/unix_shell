/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:51:04 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/21 18:47:49 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../common.h"

int	ft_cd(void);
int	ft_echo(void);
int	ft_env(void);
int	ft_exit(void);
int	ft_export(void);
int	ft_pwd(void);
int	ft_unset(void);

#endif
