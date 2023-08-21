/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:32:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:35:52 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "command.h"
#include "parser/env_replace.h"
#include "libft.h"

char		*replace_env(char *str);
static void	reset_env_replacer(t_env_replacer *env_replacer);
static int	replace_expansion(t_env_replacer *env_replacer, char *pstr);

char	*replace_env(char *str)
{
	t_env_replacer	env_replacer;
	char			*pstr;

	reset_env_replacer(&env_replacer);
	pstr = str;
	while (*pstr)
	{
		if (*pstr == '$' && !env_replacer.flag_single_quote)
			pstr += replace_expansion(&env_replacer, pstr);
		else
		{
			if (*pstr == '\'' && !env_replacer.flag_double_quote)
				env_replacer.flag_single_quote = !env_replacer.flag_single_quote;
			else if (*pstr == '\"' && !env_replacer.flag_single_quote)
				env_replacer.flag_double_quote = !env_replacer.flag_double_quote;
			add_char_env_replacer(&env_replacer, *pstr);
		}
		pstr++;
	}
	clear_buffer(&env_replacer);
	return (env_replacer.res);
}

static void	reset_env_replacer(t_env_replacer *env_replacer)
{
	env_replacer->res = ft_strdup("");
	if (!env_replacer->res)
		crash(ENOMEM, "");
	env_replacer->flag_single_quote = false;
	env_replacer->flag_double_quote = false;
	ft_memset(env_replacer->buffer, 0, BUFFER_SIZE);
	env_replacer->buffer_ind = 0;
}

static int	replace_expansion(t_env_replacer *env_replacer, char *pstr)
{
	char	*start_pstr;
	char	*env_key;

	if (*pstr != '$')
		return (-1);
	start_pstr = ++pstr;
	while (ft_isalnum(*pstr))
		pstr++;
	if (pstr - start_pstr == 0)
		add_char_env_replacer(env_replacer, '$');
	else
	{
		env_key = ft_substr(start_pstr, 0, pstr - start_pstr);
		if (!env_key)
			crash(ENOMEM, "");
		add_str_env_replacer(env_replacer, getenv(env_key));
		free(env_key);
	}
	return (pstr - start_pstr);
}
