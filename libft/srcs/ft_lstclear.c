/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:37:46 by juyyang           #+#    #+#             */
/*   Updated: 2022/12/30 23:03:05 by juyyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*target;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		target = *lst;
		*lst = (*lst)->next;
		del(target->content);
		free(target);
	}
}
