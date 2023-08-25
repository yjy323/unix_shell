/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:45:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 19:59:13 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "expand/expand.h"
#include "expand/expander.h"
#include "hashlib.h"
#include "variables.h"

char	*expand_for_heredoc(char *str)
{
	t_expander	epd;

	init_expander(&epd, str);
	while (*epd.pstr)
	{
		if (*epd.pstr == '$' && !epd.isin_singlequote)
			expand_hashdollor(&epd);
		else
		{
			add_expander_c(&epd, *epd.pstr);
			epd.pstr++;
		}
	}
	clear_expander_buffer(&epd);
	return (epd.ostr);
}
