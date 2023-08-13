/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:02:26 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/02 02:22:04 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void	crash(int errnum, char *word)
{
	(void)word;
	if (errno == ENOMEM)
		printf(STR_ENOMEM, "bash");
	exit(errnum);
}
