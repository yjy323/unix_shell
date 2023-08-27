/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_desc_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:57:17 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 20:58:56 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "command.h"
#include "expand/expand.h"

t_word_list		*word_desc_split(t_word_desc *word_desc);
static size_t	add_word_desc_to_word_list(t_word_list **word_list, char *word);

t_word_list	*word_desc_split(t_word_desc *word_desc)
{
	t_word_list	*word_list;
	char		*word;

	word = word_desc->word;
	word_list = 0;
	while (*word == ' ' || *word == '\t' || *word == '\n')
		word++;
	while (*word)
	{
		word += add_word_desc_to_word_list(&word_list, word);
		while (*word == ' ' || *word == '\t' || *word == '\n')
			word++;
	}
	return (word_list);
}

static size_t	add_word_desc_to_word_list(t_word_list **word_list, char *word)
{
	t_word_desc	*word_desc;
	char		*pend;
	size_t		size_word;

	word_desc = get_word_desc();
	pend = word;
	while (*pend \
		&& *pend != ' ' && *pend != '\t' && *pend != '\n')
	{
		if ((*pend == '\'' || *pend == '\"') && ft_strchr(pend + 1, *pend))
		{
			if (*pend == '\'')
				word_desc->flag |= W_QUOTED;
			else if (*pend == '\"')
				word_desc->flag |= W_DQUOTED;
			pend = ft_strchr(pend + 1, *pend);
		}
		pend++;
	}
	pend--;
	word_desc->word = ft_xsubstr(word, 0, pend - word + 1);
	push_word_list(word_list, word_desc);
	size_word = ft_strlen(word_desc->word);
	return (size_word);
}
