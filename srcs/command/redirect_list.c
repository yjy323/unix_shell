/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:00:16 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 20:53:42 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "status.h"
#include "command.h"
#include "utils.h"

void			init_redirect_list(t_redirect_list *redirect_list);
t_redirect_list	*get_redirect_list(void);
void			free_redirect_list(t_redirect_list *redirect_list);
void			push_redirect_list(\
					t_redirect_list **redirect_list, \
					t_redirect *redirect);
t_redirect		*pop_redirect_list(t_redirect_list **redirect_list);

void	init_redirect_list(t_redirect_list *redirect_list)
{
	redirect_list->next = 0;
	redirect_list->redirect = 0;
}

t_redirect_list	*get_redirect_list(void)
{
	t_redirect_list	*redirect_list;

	redirect_list = (t_redirect_list *)xmalloc(sizeof(t_redirect_list));
	init_redirect_list(redirect_list);
	return (redirect_list);
}

void	free_redirect_list(t_redirect_list *redirect_list)
{
	t_redirect_list	*predirect_list;

	while (redirect_list)
	{
		predirect_list = redirect_list;
		redirect_list = redirect_list->next;
		free_redirect(predirect_list->redirect);
		free(predirect_list);
	}
}

void	push_redirect_list(
	t_redirect_list **redirect_list, \
	t_redirect *redirect)
{
	t_redirect_list	*predirect_list;
	t_redirect_list	*new_redirect_list;

	predirect_list = *redirect_list;
	new_redirect_list = get_redirect_list();
	new_redirect_list->redirect = redirect;
	if (predirect_list == 0)
		*redirect_list = new_redirect_list;
	else
	{
		while (predirect_list->next)
			predirect_list = predirect_list->next;
		predirect_list->next = new_redirect_list;
	}
}

t_redirect	*pop_redirect_list(t_redirect_list **redirect_list)
{
	t_redirect		*pop_redirect;
	t_redirect_list	*rm_redirect_list;

	if (!(*redirect_list))
		return (0);
	rm_redirect_list = *redirect_list;
	pop_redirect = rm_redirect_list->redirect;
	*redirect_list = (*redirect_list)->next;
	free(rm_redirect_list);
	return (pop_redirect);
}
