/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntex_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:38:22 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 13:19:07 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/lex_list.h"
#include "status.h"

int			syntex_check(t_lex_list *pre, t_lex_list *cur);
static int	redirect_syntex_check(t_lex_list *cur);
static int	connection_syntex_check(t_lex_list *pre);

int	syntex_check(t_lex_list *pre, t_lex_list *cur)
{
	if (cur->data->type == cm_redirect)
	{
		if (redirect_syntex_check(cur) == -1)
			return (-1);
	}
	else if (cur->data->type == cm_connection)
	{
		if (connection_syntex_check(pre) == -1)
			return (-1);
	}
	return (0);
}

static int	redirect_syntex_check(t_lex_list *cur)
{
	if (!cur->next
		|| !(cur->next->data->type == cm_simple))
		{
			crash(SYNTEX_ERROR, "newline");
			return (-1);
		}
	return (0);
}

static int	connection_syntex_check(t_lex_list *pre)
{
	
	if (!pre
		|| !(pre->next->next)
		|| (pre->next->next->data->type == cm_connection))
	{
		crash(SYNTEX_ERROR, "|");
		return (-1);
	}
	return (0);
}
