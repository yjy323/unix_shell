/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:19:39 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/20 22:50:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../libft/includes/libft.h"

void		translate_env_in_node(t_node *node);
static void	translate_env(t_token *token, char *str);
static char	*strjoin_env(char *str, char *env_key);
static char	*get_env_string(const char *str);
static char	*get_word_string(const char *str);

void	translate_env_in_node(t_node *node)
{
	char	*str;
	char	*pstr;

	str = node->data->word;
	pstr = ft_strchr(str, '$');
	if (!pstr)
		return ;
	translate_env(node->data, str);
	free(str);
}

static void	translate_env(t_token *token, char *str)
{
	char	*joining_str;
	char	*del_str;

	token->word = ft_strdup("");
	if (!token->word)
		crash("", errno);
	while (*str)
	{
		del_str = token->word;
		if (*str == '$' && ft_isalnum(*(str + 1)))
		{
			joining_str = get_env_string(str);
			token->word = strjoin_env(token->word, joining_str + 1);
		}
		else
		{
			joining_str = get_word_string(str);
			token->word = ft_strjoin(token->word, joining_str);
			if (!token->word)
				crash("", errno);
		}
		str += ft_strlen(joining_str);
		free(joining_str);
		free(del_str);
	}
}

static char	*strjoin_env(char *str, char *env_key)
{
	char	*new_str;
	char	*env_val;

	env_val = getenv(env_key);
	if (env_val == 0)
		new_str = ft_strdup(str);
	else
		new_str = ft_strjoin(str, env_val);
	if (!new_str)
		crash("", errno);
	return (new_str);
}

static char	*get_env_string(const char *str)
{
	char		*env_key;
	const char	*pstr;

	if (*str != '$')
		return (0);
	pstr = str + 1;
	while (*pstr && ft_isalnum(*pstr))
		pstr++;
	env_key = ft_substr(str, 0, pstr - str);
	if (!env_key)
		crash("", errno);
	return (env_key);
}

static char	*get_word_string(const char *str)
{
	char		*word;
	const char	*pstr;

	pstr = ft_strchr(str + 1, '$');
	if (pstr)
		word = ft_substr(str, 0, pstr - str);
	else
		word = ft_strdup(str);
	return (word);
}
