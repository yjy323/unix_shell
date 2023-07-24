/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/24 17:37:55 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse/data.h"

t_node	*getnode(t_token *data);
void	free_node(t_node *node);

t_node	*getnode(t_token *data)
{
	t_node	*new_node;

	new_node = 0;
	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (!new_node)
		crash("", errno);
	new_node->parent = 0;
	new_node->left = 0;
	new_node->right = 0;
	new_node->data = data;
	return (new_node);
}

void	free_node(t_node *node)
{
	if (node->data)
		free_token(node->data);
	free(node);
}
