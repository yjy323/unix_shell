/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:30:49 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/14 03:11:54 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/tokenize.h"
#include "common/common.h"
#include "libft.h"

t_token_list	*tokenize(char *str);
static size_t	add_oper_to_token_list(t_token_list **new_token, char *str);
static size_t	add_word_to_token_list(t_token_list **new_token, char *str);

t_token_list	*tokenize(char *str)
{
	t_token_list	*token_list;

	token_list = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	while (*str)
	{
		if (*str == '|' || *str == '<' || *str == '>')
			str += add_oper_to_token_list(&token_list, str);
		else
			str += add_word_to_token_list(&token_list, str);
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
	}
	return (token_list);
}

static size_t	add_oper_to_token_list(t_token_list **token_list, char *str)
{
	char	*str_oper;
	size_t	size_oper;

	if (!ft_strncmp(str, ">>", 2) || !ft_strncmp(str, "<<", 2))
		str_oper = ft_substr(str, 0, 2);
	else
		str_oper = ft_substr(str, 0, 1);
	push_token_list(token_list, str_oper);
	size_oper = ft_strlen(str_oper);
	return (size_oper);
}

static size_t	add_word_to_token_list(t_token_list **token_list, char *str)
{
	char	*str_word;
	char	*pend;
	size_t	size_word;

	pend = str;
	while (*pend \
		&& *pend != ' ' && *pend != '\t' && *pend != '\n' \
		&& *pend != '>' && *pend != '<' && *pend != '|')
	{
		if ((*pend == '\'' || *pend == '\"')
			&& ft_strchr(pend + 1, *pend))
			pend = ft_strchr(pend + 1, *pend);
		pend++;
	}
	pend--;
	str_word = ft_substr(str, 0, pend - str + 1);
	push_token_list(token_list, str_word);
	size_word = ft_strlen(str_word);
	return (size_word);
}
