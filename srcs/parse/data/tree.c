/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:17 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/24 17:38:11 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse/data.h"

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
