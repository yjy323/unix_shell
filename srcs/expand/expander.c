/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:02:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/15 17:18:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand/expander.h"
#include "libft.h"

void	init_expander(t_expander *epd, char *istr);
void	add_expander_c(t_expander *epd, char c);
void	add_expander_str(t_expander *epd, char *str);
void	clear_expander_buffer(t_expander *epd);

void	init_expander(t_expander *epd, char *istr)
{
	epd->istr = istr;
	epd->pstr = istr;
	epd->ostr = ft_strdup("");
	ft_memset(&epd->buffer, 0, DEBS);
	epd->buffer_idx = 0;
	epd->isin_singlequote = false;
}

void	add_expander_c(t_expander *epd, char c)
{
	if (epd->buffer_idx == DEBS - 1)
		clear_expander_buffer(epd);
	epd->buffer[epd->buffer_idx++] = c;
}

void	add_expander_str(t_expander *epd, char *str)
{
	while (*str)
		add_expander_c(epd, *str++);
}

void	clear_expander_buffer(t_expander *epd)
{
	char	*tmp_str;

	tmp_str = epd->ostr;
	epd->ostr = ft_strjoin(epd->ostr, epd->buffer);
	free(tmp_str);
	ft_memset(&epd->buffer, 0, DEBS);
	epd->buffer_idx = 0;
}
