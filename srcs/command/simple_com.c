/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:23:54 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 15:10:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "command.h"
#include "error.h"
#include "utils.h"

void			init_simple_com(t_simple_com *simple_com);
t_simple_com	*get_simple_com(void);
void			clear_simple_com(t_simple_com *simple_com);
void			free_simple_com(t_simple_com *simple_com);

void	init_simple_com(t_simple_com *simple_com)
{
	simple_com->words = 0;
	simple_com->redirects = 0;
}

t_simple_com	*get_simple_com(void)
{
	t_simple_com	*simple_com;

	simple_com = (t_simple_com *)xmalloc(sizeof(t_simple_com));
	init_simple_com(simple_com);
	return (simple_com);
}

void	clear_simple_com(t_simple_com *simple_com)
{
	if (simple_com->words)
		free_word_list(simple_com->words);
	if (simple_com->redirects)
		free_redirect_list(simple_com->redirects);
	init_simple_com(simple_com);
}

void	free_simple_com(t_simple_com *simple_com)
{
	clear_simple_com(simple_com);
	free(simple_com);
}
