/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:22:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/20 22:43:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data/type_parse.h"

void	add_lchild(t_node *parent, t_node *child);
void	add_rchild(t_node *parent, t_node *child);
void	add_parent_for_lchild(t_tree *tree, t_node *parent, t_node *child);
void	add_parent_for_rchild(t_tree *tree, t_node *parent, t_node *child);

void	add_lchild(t_node *parent, t_node *child)
{
	child->parent = parent;
	parent->left = child;
}

void	add_rchild(t_node *parent, t_node *child)
{
	child->parent = parent;
	parent->right = child;
}

void	add_parent_for_lchild(t_tree *tree, t_node *parent, t_node *child)
{
	child->parent = parent;
	parent->left = child;
	if (child == tree->root)
		tree->root = parent;
}

void	add_parent_for_rchild(t_tree *tree, t_node *parent, t_node *child)
{
	child->parent = parent;
	parent->right = child;
	if (child == tree->root)
		tree->root = parent;
}
