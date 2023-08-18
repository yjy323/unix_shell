/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_nulls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:51:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/16 23:07:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "expand/expander.h"
#include "libft.h"

void		remove_quote_nulls(t_word_list *list);
static void	remove_quote_nulls_word_desc(t_word_desc *word_desc);

void	remove_quote_nulls(t_word_list *list)
{
	t_word_list	*plist;
	t_word_desc	*word_desc;

	plist = list;
	while (plist)
	{
		word_desc = plist->word;
		if (word_desc->flag & (W_QUOTED | W_DQUOTED))
			remove_quote_nulls_word_desc(word_desc);
		plist = plist->next;
	}
}

static void	remove_quote_nulls_word_desc(t_word_desc *word_desc)
{
	t_expander	epd;
	char		*pword;
	char		*tmp_str;

	init_expander(&epd, word_desc->word);
	pword = word_desc->word;
	while (*pword)
	{
		if ((*pword == '\'' || *pword == '\"')
			&& ft_strchr(pword + 1, *pword))
		{
			tmp_str = ft_substr(pword, 1, \
				ft_strchr(pword + 1, *pword) - pword - 1);
			add_expander_str(&epd, tmp_str);
			free(tmp_str);
			pword = ft_strchr(pword + 1, *pword);
		}
		else
			add_expander_c(&epd, *pword);
		pword++;
	}
	free(word_desc->word);
	clear_expander_buffer(&epd);
	word_desc->word = epd.ostr;
	word_desc->flag = word_desc->flag ^ W_QUOTED ^ W_DQUOTED;
}
