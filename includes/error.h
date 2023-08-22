/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/22 17:40:41 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>

# define SYNTEX_ERROR 1
# define SYNTEX_ERROR_MESSAGE "syntax error near unexpected token"
# define SYNTEX_ERROR_FORMAT "%s: %s `%s'\n"
# define INVOPT 2
# define ENOPMS 126
# define ENOCMD 127
# define EOPTION 255

void	crash(int errnum, char *word);

#endif
