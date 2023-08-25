/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:26:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 15:52:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse/token_list.h"
#include "utils.h"

void			init_token_list(t_token_list *token_list);
t_token_list	*get_token_list(void);
void			free_token_list(t_token_list *token_list);
void			push_token_list(t_token_list **token_list, char	*word);
char			*pop_token_list(t_token_list **token_list);

void	init_token_list(t_token_list *token_list)
{
	token_list->next = 0;
	token_list->word = 0;
}

t_token_list	*get_token_list(void)
{
	t_token_list	*token_list;

	token_list = (t_token_list *)xmalloc(sizeof(t_token_list));
	init_token_list(token_list);
	return (token_list);
}

void	free_token_list(t_token_list *token_list)
{
	t_token_list	*ptoken_list;

	while (token_list)
	{
		ptoken_list = token_list;
		token_list = token_list->next;
		free(ptoken_list->word);
		free(ptoken_list);
	}
}

void	push_token_list(t_token_list **token_list, char *word)
{
	t_token_list	*ptoken_list;
	t_token_list	*new_token_list;

	ptoken_list = *token_list;
	new_token_list = get_token_list();
	new_token_list->word = word;
	if (ptoken_list == 0)
		*token_list = new_token_list;
	else
	{
		while (ptoken_list->next)
			ptoken_list = ptoken_list->next;
		ptoken_list->next = new_token_list;
	}
}

char	*pop_token_list(t_token_list **token_list)
{
	char			*pop_word;
	t_token_list	*rm_token_list;

	if (!(*token_list))
		return (0);
	rm_token_list = *token_list;
	pop_word = rm_token_list->word;
	*token_list = (*token_list)->next;
	free(rm_token_list);
	return (pop_word);
}
