/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 17:10:48 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

# define EOPTION 255

# define SUCCESS 0
# define NOTBUILTIN 4242
# define EGENRAL 1
# define EMISUSE 2
# define ENOPERM 126
# define ENOCMD 127
# define ESIGNAL 128
# define EEXITARG 255
# define ESYNTEX 258

# define INVHOME "HOME not set"
# define INVARG "not a valid identifier"
# define INVARG_COUNT "too many arguments"
# define INVARG_NUMERIC "numeric argument required"
# define MSYNTAX "syntax error near unexpected token "
# define MNOCMD "command not found"

void	crash(int status, char *cmd, char *arg, char *msg);
int		exception_handler(int status, char *cmd, char *arg, char *msg);
void	exception_handler_sub_ps(int status, char *cmd, char *arg, char *msg);

void	print_error_msg(int status, char *cmd, char *arg, char *msg);

#endif
