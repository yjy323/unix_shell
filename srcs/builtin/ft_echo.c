/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:44:20 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 15:03:02 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"

int			ft_echo(t_word_list *list);
static bool	is_option(char *word);
static int	ft_echo_option(t_word_list **p_list, int *p_no_newline);

int	ft_echo(t_word_list *list)
{
	int		status;
	int		no_newline;

	no_newline = 0;
	status = 0;
	if (list && list->word->word && is_option(list->word->word))
		status = ft_echo_option(&list, &no_newline);
	if (status == 0)
	{
		while (list)
		{
			printf("%s", list->word->word);
			list = list->next;
			if (list)
				printf(" ");
		}
		if (no_newline == 0)
			printf("\n");
	}
	return (status);
}

static bool	is_option(char *word)
{
	if (*word != '-')
		return (false);
	while (*word++)
	{
		if (*word == '-')
			return (false);
	}
	return (true);
}

static int	ft_echo_option(t_word_list **p_list, int *p_no_newline)
{
	char	*word;

	word = (*p_list)->word->word;
	while (*(++word))
	{
		if (*word == 'n')
			*p_no_newline = 1;
		else
			return (1);
	}
	*p_list = (*p_list)->next;
	return (0);
}
