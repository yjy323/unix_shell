/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:02:26 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/22 18:05:11 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "minishell.h"

extern int	g_status;

void	crash(int errnum, char *word)
{
	if (errnum == SYNTEX_ERROR)
	{
		printf(SYNTEX_ERROR_FORMAT, SH_NAME, SYNTEX_ERROR_MESSAGE, word);
		g_status = 258;
	}

}
