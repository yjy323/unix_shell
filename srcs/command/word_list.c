/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:26:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 13:19:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "command.h"
#include "status.h"
#include "utils.h"

void		init_word_list(t_word_list *word_list);
t_word_list	*get_word_list(void);
void		free_word_list(t_word_list *word_list);
void		push_word_list(t_word_list **word_list, t_word_desc *word);
t_word_desc	*pop_word_list(t_word_list **word_list);

void	init_word_list(t_word_list *word_list)
{
	word_list->next = 0;
	word_list->word = 0;
}

t_word_list	*get_word_list(void)
{
	t_word_list	*word_list;

	word_list = (t_word_list *)xmalloc(sizeof(t_word_list));
	init_word_list(word_list);
	return (word_list);
}

void	free_word_list(t_word_list *word_list)
{
	t_word_list	*pword_list;

	while (word_list)
	{
		pword_list = word_list;
		word_list = word_list->next;
		free_word_desc(pword_list->word);
		free(pword_list);
	}
}

void	push_word_list(t_word_list **word_list, t_word_desc *word)
{
	t_word_list	*pword_list;
	t_word_list	*new_word_list;

	pword_list = *word_list;
	new_word_list = get_word_list();
	new_word_list->word = word;
	if (pword_list == 0)
		*word_list = new_word_list;
	else
	{
		while (pword_list->next)
			pword_list = pword_list->next;
		pword_list->next = new_word_list;
	}
}

t_word_desc	*pop_word_list(t_word_list **word_list)
{
	t_word_desc	*pop_word_desc;
	t_word_list	*rm_word_list;

	if (!(*word_list))
		return (0);
	rm_word_list = *word_list;
	pop_word_desc = rm_word_list->word;
	*word_list = (*word_list)->next;
	free(rm_word_list);
	return (pop_word_desc);
}
