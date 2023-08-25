/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:47:48 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 19:59:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "command.h"
#include "expand/expander.h"
#include "expand/expand.h"
#include "hashlib.h"
#include "variables.h"
#include "libft.h"

void		expand_word(t_word_desc *word);
static char	*expand_str(char *str);

void	expand_word(t_word_desc *word)
{
	char	*new_str;

	new_str = expand_str(word->word);
	word->flag = (word->flag) ^ W_HASDOLLAR;
	free(word->word);
	word->word = new_str;
}

static char	*expand_str(char *str)
{
	t_expander	epd;

	init_expander(&epd, str);
	while (*epd.pstr)
	{
		if (*epd.pstr == '$' && !epd.isin_singlequote)
			expand_hashdollor(&epd);
		else
		{
			if (*epd.pstr == '\'' \
				&& (epd.isin_singlequote || ft_strchr(epd.pstr + 1, '\'')))
				epd.isin_singlequote = !epd.isin_singlequote;
			add_expander_c(&epd, *epd.pstr);
			epd.pstr++;
		}
	}
	clear_expander_buffer(&epd);
	return (epd.ostr);
}
