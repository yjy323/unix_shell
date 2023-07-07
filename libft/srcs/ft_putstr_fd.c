/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:31:39 by juyyang           #+#    #+#             */
/*   Updated: 2023/01/24 15:08:33 by juyyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	char	*null_pointer;

	null_pointer = "(null)";
	if (fd < 0)
		return (-1);
	if (s == 0)
		s = null_pointer;
	return (write(fd, s, ft_strlen(s)));
}
