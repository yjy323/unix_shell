/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_desc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:49:32 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/16 22:40:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"

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
