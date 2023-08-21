/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:23:54 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:35:52 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void			init_simple_com(t_simple_com *simple_com);
t_simple_com	*get_simple_com(void);
void			clear_simple_com(t_simple_com *simple_com);
void			free_simple_com(t_simple_com *simple_com);

void	init_simple_com(t_simple_com *simple_com)
{
	simple_com->words = 0;
	simple_com->redirects = 0;
	simple_com->connection = 0;
}

t_simple_com	*get_simple_com(void)
{
	t_simple_com	*simple_com;

	simple_com = (t_simple_com *)malloc(sizeof(t_simple_com));
	if (!simple_com)
		crash(ENOMEM, 0);
	init_simple_com(simple_com);
	return (simple_com);
}

void	clear_simple_com(t_simple_com *simple_com)
{
	if (simple_com->words)
		free_word_list(simple_com->words);
	if (simple_com->redirects)
		free_redirect_list(simple_com->redirects);
	if (simple_com->connection)
		free_connection(simple_com->connection);
	init_simple_com(simple_com);
}

void	free_simple_com(t_simple_com *simple_com)
{
	clear_simple_com(simple_com);
	free(simple_com);
}
