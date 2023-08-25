/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:18:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 13:42:11 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_LIST_H
# define TOKEN_LIST_H

typedef struct s_token_list {
	char				*word;
	struct s_token_list	*next;
}t_token_list;

void			init_token_list(t_token_list *token_list);
t_token_list	*get_token_list(void);
void			free_token_list(t_token_list *token_list);
void			push_token_list(t_token_list **token_list, char	*word);
char			*pop_token_list(t_token_list **token_list);

#endif