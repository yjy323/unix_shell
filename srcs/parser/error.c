/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:09:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/14 15:29:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "../../libft/includes/libft.h"
#include <string.h>

void	print_error(int errno_type)
{
	char	*error_message;

	error_message = strerror(errno_type);
	write(2, error_message, ft_strlen(error_message));
	exit(errno_type);
}
