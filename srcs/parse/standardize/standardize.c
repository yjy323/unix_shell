/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standardize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:10:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 15:32:12 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/syntex.h"
#include "heredoc.h"
#include "parse/lex_list.h"
#include "variables.h"
#include "libft.h"

int			standardize(t_lex_list *list, t_sh_variable *sh_variable);
static int	standardize_internal(t_lex_list *qlist, t_lex_list *plist, \
								t_sh_variable *sh_variable, int *heredoc_num);

int	standardize(t_lex_list *list, t_sh_variable *sh_variable)
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
		if (standardize_internal(qlist, plist, sh_variable, &heredoc_num) == -1)
			return (-1);
		qlist = plist;
		plist = plist->next;
	}
	return (0);
}

static int	standardize_internal(t_lex_list *qlist, t_lex_list *plist, \
								t_sh_variable *sh_variable, int *heredoc_num)
{
	if (plist->data->type == cm_simple)
		return (0);
	if (syntex_check(qlist, plist) == -1)
		return (-1);
	if (plist->data->type == cm_redirect
		&& ft_strncmp(plist->data->word, "<< ", 3))
	{
		if (take_heredoc(plist, sh_variable, (*heredoc_num)++) == 1)
			return (-1);
	}
	return (0);
}
