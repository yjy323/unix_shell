/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:06:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/20 22:57:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <stdbool.h>
# include <stdlib.h>
# include "type_parse.h"

// token
t_token	*get_token(void);
void	free_token(t_token *token);
t_token	*get_token_with_data(const char *word, t_type type);

// node
t_node	*getnode(t_token *data);
void	free_node(t_node *node);

// list
void	init_token_list(t_token_list *lst);
bool	isempty_token_list(t_token_list *lst);
void	clear_token_list(t_token_list *lst);
void	push_front(t_token_list *lst, t_node *node);
void	push_back(t_token_list *lst, t_node *node);
t_node	*pop_front(t_token_list *lst);
t_node	*pop_back(t_token_list *lst);

// tree
void	init_tree(t_tree *tree);
void	clear_tree(t_tree *tree);
void	add_lchild(t_node *parent, t_node *child);
void	add_rchild(t_node *parent, t_node *child);
void	add_parent_for_lchild(t_tree *tree, t_node *parent, t_node *child);
void	add_parent_for_rchild(t_tree *tree, t_node *parent, t_node *child);

#endif