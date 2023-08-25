/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:01:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 13:45:03 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "libft.h"

void	*xmalloc(size_t bytes);
void	*xrealloc(void *ptr, size_t bytes);

void	*xmalloc(size_t bytes)
{
	void	*temp;

	temp = malloc(bytes);
	if (temp == 0)
	{
		printf("%s: cannot allocate %lu bytes", \
			"xmalloc", (unsigned long)bytes);
		exit(ENOMEM);
	}
	return (temp);
}

void	*xrealloc(void *ptr, size_t bytes)
{
	void	*temp;

	temp = xmalloc(bytes);
	ft_memmove(temp, ptr, bytes);
	free(ptr);
	return (temp);
}
