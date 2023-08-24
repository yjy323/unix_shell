/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:20:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 15:09:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "command.h"
#include "error.h"
#include "utils.h"

void		init_redirect(t_redirect *redirect);
t_redirect	*get_redirect(void);
void		clear_redirect(t_redirect *redirect);
void		free_redirect(t_redirect *redirect);

void	init_redirect(t_redirect *redirect)
{
	redirect->filename = 0;
	redirect->word = 0;
}

t_redirect	*get_redirect(void)
{
	t_redirect	*redirect;

	redirect = (t_redirect *)xmalloc(sizeof(t_redirect));
	init_redirect(redirect);
	return (redirect);
}

void	clear_redirect(t_redirect *redirect)
{
	if (redirect->filename)
		free(redirect->filename);
	if (redirect->word)
		free(redirect->word);
	init_redirect(redirect);
}

void	free_redirect(t_redirect *redirect)
{
	if (redirect->filename)
		free(redirect->filename);
	if (redirect->word)
		free(redirect->word);
	free(redirect);
}
