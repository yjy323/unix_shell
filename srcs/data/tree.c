/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:17 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/20 22:43:27 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data/data.h"

void		init_tree(t_tree *tree);
void		clear_tree(t_tree *tree);
static void	clear_tree_using_recursion(t_node *root);

void	init_tree(t_tree *tree)
{	
	tree->root = 0;
}

void	clear_tree(t_tree *tree)
{
	if (!(tree->root))
		return ;
	clear_tree_using_recursion((tree)->root);
}

static void	clear_tree_using_recursion(t_node *root)
{
	if (!root)
		return ;
	clear_tree_using_recursion(root->left);
	clear_tree_using_recursion(root->right);
	free_node(root);
}
