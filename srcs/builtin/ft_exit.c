/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:38:32 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 20:52:30 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"

#include "minishell.h"
#include "status.h"
#include "prompt.h"
#include "command.h"

int			ft_exit(t_word_list *list);
static bool	valid_argument(char *word);

int	ft_exit(t_word_list *list)
{
	int	status;

	if (!list)
		status = g_sh_variable.status;
	else
	{
		if (list->next)
			return (exception_handler(EGENRAL, "exit", 0, INVARG_COUNT));
		if (valid_argument(list->word->word) == false)
			return (exception_handler(EEXITARG,
					"exit", list->word->word, INVARG_NUMERIC));
		status = ft_atoi(list->word->word) % 256;
	}
	write(1, "exit\n", 5);
	destroy();
	g_sh_variable.status = status;
	exit (status);
}

static bool	valid_argument(char *word)
{
	int		cnt;
	int		flag_neg;
	char	*longlong_max;

	cnt = 0;
	flag_neg = 0;
	if (*word == '-' || *word == '+')
	{
		word++;
		flag_neg = 1;
	}
	if (flag_neg)
		longlong_max = "9223372036854775808";
	else
		longlong_max = "9223372036854775807";
	while (word[cnt])
	{
		if (!(word[cnt] >= '0' && word[cnt] <= '9'))
			return (false);
		cnt++;
	}
	if (cnt > 19 || (cnt == 19 && ft_strncmp(longlong_max, word, 19) < 0))
		return (false);
	return (true);
}
