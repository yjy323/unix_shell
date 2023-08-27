/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:01:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 21:00:45 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

#include "status.h"

void	*xmalloc(size_t bytes);
void	*xrealloc(void *ptr, size_t bytes);

void	*xmalloc(size_t bytes)
{
	void	*temp;

	temp = malloc(bytes);
	if (temp == 0)
		crash(EGENRAL, "xalloc()", 0, 0);
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
