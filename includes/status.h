/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 05:35:11 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

# define SYNTEX_ERROR 1
# define SYNTEX_ERROR_MESSAGE "syntax error near unexpected token"
# define SYNTEX_ERROR_FORMAT "%s: %s `%s'\n"
# define EOPTION 255

# define SUCCESS 0
# define EGENRAL 1
# define EMISUSE 2
# define ENOPERM 126
# define ENOCOMD 127
# define ESIGNAL 128

# define MNOPERM ""
# define MNOCOMD ""

void	crash(int status, char *arg_str);
int		exception_handler(int status, char *arg_str);
void	exception_handler_sub_ps(int status, char *arg_str);
void	print_error_msg(int status, char *arg_str);

#endif
