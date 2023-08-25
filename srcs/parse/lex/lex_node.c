/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:50:23 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 15:52:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse/lex_list.h"
#include "utils.h"

void			init_lex_node(t_lex_node *lex_node);
t_lex_node		*get_lex_node(void);
void			free_lex_node(t_lex_node *lex_node);

void	init_lex_node(t_lex_node *lex_node)
{
	lex_node->word = 0;
	lex_node->type = -1;
	lex_node->flag = 0;
}

t_lex_node	*get_lex_node(void)
{
	t_lex_node	*lex_node;

	lex_node = (t_lex_node *)xmalloc(sizeof(t_lex_node));
	init_lex_node(lex_node);
	return (lex_node);
}

void	free_lex_node(t_lex_node *lex_node)
{
	if (lex_node->word)
		free(lex_node->word);
	free(lex_node);
}
