/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_desc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:49:32 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 20:53:52 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "status.h"
#include "command.h"
#include "utils.h"

void		init_word_desc(t_word_desc *word_desc);
t_word_desc	*get_word_desc(void);
void		clear_word_desc(t_word_desc *word_desc);
void		free_word_desc(t_word_desc *word_desc);

void	init_word_desc(t_word_desc *word_desc)
{
	word_desc->word = 0;
	word_desc->flag = 0;
}

t_word_desc	*get_word_desc(void)
{
	t_word_desc	*word_desc;

	word_desc = (t_word_desc *)xmalloc(sizeof(t_word_desc));
	init_word_desc(word_desc);
	return (word_desc);
}

void	clear_word_desc(t_word_desc *word_desc)
{
	if (word_desc->word)
		free(word_desc->word);
	init_word_desc(word_desc);
}

void	free_word_desc(t_word_desc *word_desc)
{
	if (word_desc->word)
		free(word_desc->word);
	free(word_desc);
}
