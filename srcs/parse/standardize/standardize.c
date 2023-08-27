/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standardize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:10:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 20:59:53 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "parse/syntex.h"
#include "parse/heredoc.h"
#include "parse/lex_list.h"
#include "variables.h"

int			standardize(t_lex_list *list);
static int	standardize_internal(t_lex_list *qlist, t_lex_list *plist, \
								int *heredoc_num);

int	standardize(t_lex_list *list)
{
	t_lex_list	*plist;
	t_lex_list	*qlist;
	int			heredoc_num;

	qlist = 0;
	plist = list;
	heredoc_num = 0;
	while (plist && plist->data->type == cm_simple)
	{
		qlist = plist;
		plist = plist->next;
	}
	while (plist)
	{
		if (standardize_internal(qlist, plist, &heredoc_num) == -1)
			return (-1);
		qlist = plist;
		plist = plist->next;
	}
	return (0);
}

static int	standardize_internal(t_lex_list *qlist, t_lex_list *plist, \
								int *heredoc_num)
{
	if (plist->data->type == cm_simple)
		return (0);
	if (syntex_check(qlist, plist) == -1)
		return (-1);
	if (plist->data->type == cm_redirect
		&& ft_strncmp(plist->data->word, "<<", 3) == 0)
	{
		if (take_heredoc(plist, (*heredoc_num)++) == 1)
			return (-1);
	}
	return (0);
}
