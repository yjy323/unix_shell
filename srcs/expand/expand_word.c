/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:47:48 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 20:58:35 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft.h"

#include "command.h"
#include "expand/expander.h"
#include "expand/expand.h"
#include "hashlib.h"
#include "variables.h"

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
			if (*epd.pstr == '\"' && !epd.isin_singlequote \
				&& (epd.isin_doublequote || ft_strchr(epd.pstr + 1, '\"')))
				epd.isin_doublequote = !epd.isin_doublequote;
			if (*epd.pstr == '\'' && !epd.isin_doublequote \
				&& (epd.isin_singlequote || ft_strchr(epd.pstr + 1, '\'')))
				epd.isin_singlequote = !epd.isin_singlequote;
			add_expander_c(&epd, *epd.pstr);
			epd.pstr++;
		}
	}
	clear_expander_buffer(&epd);
	return (epd.ostr);
}
