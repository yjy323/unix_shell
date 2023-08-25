/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:44:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/11 17:12:25 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

typedef struct s_token_list {
	char				*word;
	struct s_token_list	*next;
}t_token_list;

t_token_list	*tokenize(char *str);

/* token_list */
void			init_token_list(t_token_list *token_list);
t_token_list	*get_token_list(void);
void			free_token_list(t_token_list *token_list);
void			push_token_list(t_token_list **token_list, char	*word);
char			*pop_token_list(t_token_list **token_list);

#endif