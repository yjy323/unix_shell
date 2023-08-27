/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:58:17 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 15:09:13 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "execute.h"

t_redir_flag	get_redir_flag(char *redirector)
{
	if (*(redirector + 1))
	{
		if (*redirector == '<' && *(redirector + 1) == '<')
			return (redir_here_doc);
		else if (*redirector == '>' && *(redirector + 1) == '>')
			return (redir_out_append);
	}
	else
	{
		if (*redirector == '<')
			return (redir_in);
		else if (*redirector == '>')
			return (redir_out);
	}
	return (redir_err);
}
