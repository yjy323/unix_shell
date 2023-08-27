/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:26:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/09 23:48:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse/lex_list.h"
#include "utils.h"

void		init_lex_list(t_lex_list *lex_list);
t_lex_list	*get_lex_list(void);
void		free_lex_list(t_lex_list *lex_list);
void		push_lex_list(t_lex_list **lex_list, t_lex_node *word);
t_lex_node	*pop_lex_list(t_lex_list **lex_list);

void	init_lex_list(t_lex_list *lex_list)
{
	lex_list->next = 0;
	lex_list->data = 0;
}

t_lex_list	*get_lex_list(void)
{
	t_lex_list	*lex_list;

	lex_list = (t_lex_list *)xmalloc(sizeof(t_lex_list));
	init_lex_list(lex_list);
	return (lex_list);
}

void	free_lex_list(t_lex_list *lex_list)
{
	t_lex_list	*plex_list;

	while (lex_list)
	{
		plex_list = lex_list;
		lex_list = lex_list->next;
		free_lex_node(plex_list->data);
		free(plex_list);
	}
}

void	push_lex_list(t_lex_list **lex_list, t_lex_node *data)
{
	t_lex_list	*plex_list;
	t_lex_list	*new_lex_list;

	plex_list = *lex_list;
	new_lex_list = get_lex_list();
	new_lex_list->data = data;
	if (plex_list == 0)
		*lex_list = new_lex_list;
	else
	{
		while (plex_list->next)
			plex_list = plex_list->next;
		plex_list->next = new_lex_list;
	}
}

t_lex_node	*pop_lex_list(t_lex_list **lex_list)
{
	t_lex_node	*pop_lex_node;
	t_lex_list	*rm_lex_list;

	if (!(*lex_list))
		return (0);
	rm_lex_list = *lex_list;
	pop_lex_node = rm_lex_list->data;
	*lex_list = (*lex_list)->next;
	free(rm_lex_list);
	return (pop_lex_node);
}
