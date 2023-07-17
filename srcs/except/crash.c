/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:51:59 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 11:54:43 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../libft/includes/libft.h"

void	crash(int errnum)
{
	char	*error_message;

	error_message = strerror(errnum);
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n", 1);
	exit(errnum);
}
