/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:22:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/24 17:38:09 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse/data.h"

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
