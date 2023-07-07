/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:48:40 by juyyang           #+#    #+#             */
/*   Updated: 2023/01/02 17:06:15 by juyyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;
	t_list	*new_content;

	if (!lst || !f || !del)
		return (0);
	start = 0;
	while (lst)
	{
		new_content = f(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			free (new_content);
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}
