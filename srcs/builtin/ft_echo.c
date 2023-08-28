/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:44:20 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/28 14:23:40 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"

int					ft_echo(t_word_list *list);
static t_word_list	*set_option(t_word_list *list, int *p_no_newline);
static void			print_all(t_word_list *list);

int	ft_echo(t_word_list *list)
{
	int		no_newline;

	no_newline = 0;
	list = set_option(list, &no_newline);
	print_all(list);
	if (no_newline == 0)
		printf("\n");
	return (0);
}

static t_word_list	*set_option(t_word_list *list, int *p_no_newline)
{
	char	*word;

	while (list)
	{
		word = list->word->word;
		if (*word != '-')
			return (list);
		while (*(++word))
		{
			if (*word == 'n')
				*p_no_newline = 1;
			else
			{
				*p_no_newline = 0;
				break ;
			}
		}
		list = list->next;
	}
	return (list);
}

static void	print_all(t_word_list *list)
{
	while (list)
	{
		printf("%s", list->word->word);
		if (list->next)
			printf(" ");
		list = list->next;
	}
}
