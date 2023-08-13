/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/02 00:25:21 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>

# define STR_ENOMEM "%s: Out of memory\n"

void	crash(int errnum, char *word);

#endif
