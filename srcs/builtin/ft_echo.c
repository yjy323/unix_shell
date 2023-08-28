/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:44:20 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 23:18:57 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"

int			ft_echo(t_word_list *list);
static bool	is_option(char *word);
static void	ft_echo_option(t_word_list *list, int *p_no_newline);

int	ft_echo(t_word_list *list)
{
	int		status;
	int		no_newline;
	int		option_on;

	no_newline = 0;
	option_on = 1;
	status = 0;
	while (list && list->word && list->word->word)
	{
		if (option_on && is_option(list->word->word))
			ft_echo_option(list, &no_newline);
		else
		{
			printf("%s", list->word->word);
			if (list->next)
				printf(" ");
			option_on = 0;
		}
		list = list->next;
	}
	if (no_newline == 0)
		printf("\n");
	return (status);
}

static bool	is_option(char *word)
{
	if (*word != '-')
		return (false);
	while (*word++)
	{
		if (*word != 'n' && *word != 0)
			return (false);
	}
	return (true);
}

static void	ft_echo_option(t_word_list *list, int *p_no_newline)
{
	char	*word;

	word = list->word->word;
	while (*(++word))
	{
		if (*word == 'n')
			*p_no_newline = 1;
		else
			return ;
	}
}
