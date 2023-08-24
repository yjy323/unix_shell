/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:24:23 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 13:54:17 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "parser/lex.h"
#include "variables.h"
#include "libft.h"

void	expand_heredoc(t_lex_list *list, t_sh_variable *sh_variable)
{
	t_lex_list	*plist;
	char		*filename;
	char		*dir_tmp = ft_strjoin(sh_variable->mwd, "/tmp/");
	int			filenum = 0;

	plist = list;
	while (plist)
	{
		if (plist->data->type == cm_redirect
			&& ft_strncmp(plist->data->word, "<<", 3) == 0)
		{
			filename = ft_strjoin(dir_tmp, ft_itoa(filenum++));
			do_here_doc(filename, plist->next->data->word, sh_variable->environment);
			free(plist->next->data->word);
			plist->next->data->word = filename;
		}
		plist = plist->next;
	}
}