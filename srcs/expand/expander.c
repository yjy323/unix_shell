/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:02:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 20:58:50 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "expand/expander.h"

void	init_expander(t_expander *epd, char *istr);
void	add_expander_c(t_expander *epd, char c);
void	add_expander_str(t_expander *epd, char *str);
void	clear_expander_buffer(t_expander *epd);

void	init_expander(t_expander *epd, char *istr)
{
	epd->istr = istr;
	epd->pstr = istr;
	epd->ostr = ft_xstrdup("");
	ft_memset(&epd->buffer, 0, DEBS);
	epd->buffer_idx = 0;
	epd->isin_doublequote = false;
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
	epd->ostr = ft_xstrjoin(epd->ostr, epd->buffer);
	free(tmp_str);
	ft_memset(&epd->buffer, 0, DEBS);
	epd->buffer_idx = 0;
}
