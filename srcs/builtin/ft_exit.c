/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:38:32 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 15:03:09 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "command.h"
#include "libft.h"

int			ft_exit(t_word_list *list, int status);
static bool	valid_argument(char *word);

int	ft_exit(t_word_list *list, int status)
{
	if (!list)
		exit(status);
	else
	{
		if (valid_argument(list->word->word) == false)
			return (1);
		exit(ft_atoi(list->word->word));
	}
}

static bool	valid_argument(char *word)
{
	while (*word)
	{
		if (!(*word >= '0' && *word <= '9'))
			return (false);
		word++;
	}
	return (true);
}
