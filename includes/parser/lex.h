/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:17:50 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:57:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# include "command.h"
# include "tokenize.h"

typedef struct s_lex_node {
	char				*word;
	t_command_type		type;
	int					flag;
}t_lex_node;

typedef struct s_lex_list {
	struct s_lex_list	*next;
	t_lex_node			*data;
}t_lex_list;

t_lex_list		*lex(char *str);

/* lex_node */
void			init_lex_node(t_lex_node *lex_node);
t_lex_node		*get_lex_node(void);
void			free_lex_node(t_lex_node *lex_node);

/* lex_list */
void			init_lex_list(t_lex_list *lex_list);
t_lex_list		*get_lex_list(void);
void			free_lex_list(t_lex_list *lex_list);
void			push_lex_list(t_lex_list **lex_list, t_lex_node *node);
t_lex_node		*pop_lex_list(t_lex_list **lex_list);

#endif