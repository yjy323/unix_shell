/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:54:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/20 22:42:57 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data/data.h"

void	init_token_list(t_token_list *lst);
bool	isempty_token_list(t_token_list *lst);
void	clear_token_list(t_token_list *lst);

void	init_token_list(t_token_list *lst)
{
	lst->front = 0;
	lst->rear = 0;
}

bool	isempty_token_list(t_token_list *lst)
{
	if (lst->front == 0)
		return (true);
	else
		return (false);
}

void	clear_token_list(t_token_list *lst)
{
	while (!isempty_token_list(lst))
		free_node(pop_front(lst));
	free(lst);
}
