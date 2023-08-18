/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:47:48 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/15 17:55:27 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "common/common.h"
#include "expand/expander.h"
#include "libft.h"

void		expand_word(t_word_desc *word);
char		*expand_str(char *str);
static void	expand_hashdollor(t_expander *epd);
static void	expand_question(t_expander *epd);
static void	expand_env(t_expander *epd);

void	expand_word(t_word_desc *word)
{
	char	*new_str;

	new_str = expand_str(word->word);
	word->flag = (word->flag) ^ W_HASDOLLAR;
	free(word->word);
	word->word = new_str;
}

char	*expand_str(char *str)
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

static void	expand_hashdollor(t_expander *epd)
{
	if (ft_strncmp(epd->pstr, "$?", 2) == 0)
		expand_question(epd);
	else if (!ft_isalnum(*(epd->pstr + 1)))
	{
		add_expander_c(epd, '$');
		epd->pstr++;
	}
	else
		expand_env(epd);
}

static void	expand_question(t_expander *epd)
{
	char	*str_exit_num;

	str_exit_num = ft_strdup("[exit code]");
	// str_exit_num = ft_itoa(?)
	add_expander_str(epd, str_exit_num);
	epd->pstr = epd->pstr + 2;
	free(str_exit_num);
}

static void	expand_env(t_expander *epd)
{
	char	*env_key;
	char	*skey;
	char	*ekey;
	char	*env_val;

	skey = epd->pstr;
	ekey = epd->pstr + 1;
	while (ft_isalnum(*ekey))
		ekey++;
	env_key = ft_substr(skey, 1, ekey - skey - 1);
	env_val = getenv(env_key);
	if (env_val)
		add_expander_str(epd, env_val);
	epd->pstr = epd->pstr + ft_strlen(env_key) + 1;
	free(env_key);
}
