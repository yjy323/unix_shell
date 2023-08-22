/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/22 14:01:48 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>

# define INVOPT 2
# define ENOPMS 126
# define ENOCMD 127
# define EOPTION 255

void	crash(int errnum, char *word);

#endif
