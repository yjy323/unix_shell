/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:46:07 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/13 20:48:26 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/type.h"

void	free_pid_list(t_pid_list *head)
{
	t_pid_list	*iter;
	t_pid_list	*del;

	if (head)
	{
		iter = head;
		while (iter)
		{
			del = iter;
			iter = iter->next;
			free(del);
		}
	}
}

void	free_vector(char **vector)
{
	char	*del;
	size_t	i;

	del = *vector;
	i = 0;
	while (vector[i])
	{
		i++;
		free(del);
		del = vector[i];
	}
	free(vector);
}
