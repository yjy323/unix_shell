/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:52:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/24 17:38:35 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse/parse.h"

void		valid_syntax(t_token_list *lst);
static void	valid_pipeline(t_node *node);
static void	valid_redirect(t_node *node);

void	valid_syntax(t_token_list *lst)
{
	t_node	*node;
	t_type	type;

	node = lst->front;
	while (node)
	{
		type = node->data->type;
		if (type == PIPELINE)
			valid_pipeline(node);
		else if (type == REDIRECT)
			valid_redirect(node);
		node = node->right;
	}
}

static void	valid_pipeline(t_node *node)
{
	if (!(node->left) || !(node->right)
		|| !(node->left->data->type == WORD)
		|| !(node->right->data->type == WORD))
		crash("", errno);
}

static void	valid_redirect(t_node *node)
{
	if (!(node->right)
		|| !(node->right->data->type == WORD))
		crash("", errno);
}
