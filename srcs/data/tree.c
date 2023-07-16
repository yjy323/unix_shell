/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:17 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/11 21:46:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/type.h"

void		init_tree(t_tree *tree);
void		free_tree(t_tree *tree);
static void	free_tree_using_recursion(t_node *root);

void	init_tree(t_tree *tree)
{	
	tree->root = 0;
}

void	free_tree(t_tree *tree)
{
	if (!((tree)->root))
		return ;
	free_tree_using_recursion((tree)->root);
	free(tree);
}

static void	free_tree_using_recursion(t_node *root)
{
	if (!root)
		return ;
	free_tree_using_recursion(root->left);
	free_tree_using_recursion(root->right);
	free(root);
}
