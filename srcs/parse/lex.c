/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:46:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/14 14:17:12 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../libft/includes/libft.h"

void			lex(t_token_list *lst_token, t_token_list *lst_lex);
static void		push_to_lex(t_token_list *lex, t_node *node, t_type *pre_type);
static void		merge_push_to_lex(t_token_list *lst, t_node *node);
static int		trim_quote_in_node(t_node *node);

void	lex(t_token_list *lst_token, t_token_list *lst_lex)
{
	t_node			*pnode;
	t_type			pre_type;

	pre_type = -1;
	while (!isempty_token_list(lst_token))
	{
		pnode = pop_front(lst_token);
		push_to_lex(lst_lex, pnode, &pre_type);
	}
}

static void	push_to_lex(t_token_list *lst_lex, t_node *node, t_type *pre_type)
{
	t_type			type;

	type = node->data->type;
	if (type == SPACE)
		free_node(node);
	else if (type == PIPELINE || type == REDIRECT)
		push_back(lst_lex, node);
	else
	{
		if (type == DOUBLE_QUOTE || type == WORD)
			translate_env_in_node(node);
		if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
			trim_quote_in_node(node);
		type = node->data->type;
		if (type == WORD && *pre_type == WORD)
			merge_push_to_lex(lst_lex, node);
		else
			push_back(lst_lex, node);
	}
	*pre_type = type;
}

static void	merge_push_to_lex(t_token_list *lst, t_node *node)
{
	t_node	*pre_node;
	t_node	*res_node;
	char	*new_str;

	pre_node = pop_back(lst);
	new_str = ft_strjoin(pre_node->data->word, node->data->word);
	if (!new_str)
		crash("", errno);
	res_node = getnode(get_token_with_data(new_str, WORD));
	free(new_str);
	free_node(pre_node);
	free_node(node);
	push_back(lst, res_node);
}

static int	trim_quote_in_node(t_node *node)
{
	char	*pre_word;
	char	*update_word;

	pre_word = node->data->word;
	if (*pre_word == '\'')
		update_word = ft_strtrim(pre_word, "\'");
	else
		update_word = ft_strtrim(pre_word, "\"");
	if (!update_word)
		crash("", errno);
	node->data->word = update_word;
	node->data->type = WORD;
	free(pre_word);
	return (0);
}
