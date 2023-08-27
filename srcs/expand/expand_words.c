/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:21:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 20:58:41 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "command.h"
#include "expand/expand.h"
#include "expand/expander.h"
#include "variables.h"

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
		word_desc->word = ft_xstrdup(list->word->word);
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
