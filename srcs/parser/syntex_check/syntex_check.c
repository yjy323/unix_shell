/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntex_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:22:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/23 15:07:52 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "parser/lex.h"

bool		syntex_check(t_lex_list *lex_list);
static bool	redirect_syntex_check(t_lex_list *lex_list);
static bool	connection_syntex_check(t_lex_list *pre_lex_list);

bool	syntex_check(t_lex_list *lex_list)
{
	t_lex_list	*plex_list;
	t_lex_list	*pre_lex_list;

	plex_list = lex_list;
	pre_lex_list = 0;
	while (plex_list)
	{
		if (plex_list->data->type == cm_redirect)
		{
			if (redirect_syntex_check(plex_list) == false)
				return (false);
		}
		else if (plex_list->data->type == cm_connection)
		{
			if (connection_syntex_check(pre_lex_list) == false)
				return (false);
		}
		pre_lex_list = plex_list;
		plex_list = plex_list->next;
	}
	return (true);
}

static bool	redirect_syntex_check(t_lex_list *lex_list)
{
	if (!lex_list->next
		|| !(lex_list->next->data->type == cm_simple))
	{
		crash(SYNTEX_ERROR, "newline");
		return (false);
	}
	return (true);
}

static bool	connection_syntex_check(t_lex_list *pre_lex_list)
{
	if (!pre_lex_list
		|| !(pre_lex_list->next->next)
		|| (pre_lex_list->next->next->data->type == cm_connection))
	{
		crash(SYNTEX_ERROR, "|");
		return (false);
	}
	return (true);
}
