/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:33:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/14 15:46:01 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void			parse_tree(t_token_list *lst_token, t_tree *ast);
static void		add_node_to_ast_tree(t_tree *tree, t_node *via, t_node *node, \
									t_type pre_type);
static t_node	*get_eor_node(t_node *node);

void	parse_tree(t_token_list *lst_token, t_tree *ast)
{
	t_node	*pnode;
	t_type	pre_type;

	ast->root = getnode(get_token_with_data(0, COMMAND));
	while (!isempty_token_list(lst_token))
	{
		pnode = pop_front(lst_token);
		add_node_to_ast_tree(ast, ast->root, pnode, pre_type);
		pre_type = pnode->data->type;
	}
}

static void	add_node_to_ast_tree(t_tree *tree, t_node *via, t_node *node, \
								t_type pre_type)
{
	t_type	type;
	t_type	via_type;

	type = node->data->type;
	via_type = via->data->type;
	if (type == PIPELINE)
		add_parent_for_lchild(tree, node, tree->root);
	else if (via_type == PIPELINE)
	{
		if (via->right == 0)
			add_rchild(via, getnode(get_token_with_data(0, COMMAND)));
		add_node_to_ast_tree(tree, via->right, node, pre_type);
	}
	else if (pre_type == REDIRECT || type == REDIRECT)
		add_rchild(get_eor_node(via), node);
	else
	{
		if (!(via->left))
			add_lchild(via, node);
		else
			add_rchild(get_eor_node(via->left), node);
	}
}

static t_node	*get_eor_node(t_node *node)
{
	while (node->right)
		node = node->right;
	return (node);
}
