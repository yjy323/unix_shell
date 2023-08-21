/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:21:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:58:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "expand/expand.h"
#include "expand/expander.h"
#include "libft.h"

t_word_list	*expand_words(t_word_list *list);
static void	move_word_list(t_word_list **src, t_word_list **dst);

t_word_list	*expand_words(t_word_list *list)
{
	t_word_list	*new_list;
	t_word_list	*tmp_list;
	t_word_desc	*word_desc;

	new_list = 0;
	while (list)
	{
		word_desc = get_word_desc();
		word_desc->flag = list->word->flag;
		word_desc->word = ft_strdup(list->word->word);
		if (word_desc->flag | W_HASDOLLAR)
			expand_word(word_desc);
		tmp_list = word_desc_split(word_desc);
		if (word_desc->flag | W_QUOTED | W_DQUOTED)
			remove_quote_nulls(tmp_list);
		move_word_list(&tmp_list, &new_list);
		list = list->next;
		free_word_desc(word_desc);
	}
	return (new_list);
}

static void	move_word_list(t_word_list **src, t_word_list **dst)
{
	while (*src)
		push_word_list(dst, pop_word_list(src));
}
