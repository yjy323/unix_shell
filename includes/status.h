/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 15:58:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

int	g_status;

# define EOPTION 255

# define SUCCESS 0
# define EGENRAL 1
# define EMISUSE 2
# define ENOPERM 126
# define ENOCOMD 127
# define ESIGNAL 128
# define ESYNTEX 258

# define MNOPERM ""
# define MNOCOMD ""

void	crash(int status, char *arg_str);
int		exception_handler(int status, char *arg_str);
void	exception_handler_sub_ps(int status, char *arg_str);
void	print_error_msg(int status, char *arg_str);

#endif
