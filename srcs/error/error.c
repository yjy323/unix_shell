/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:02:26 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/22 16:20:48 by youjeong         ###   ########.fr       */
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