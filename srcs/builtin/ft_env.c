/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:28:53 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/21 20:35:52 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "command.h"
#include "hashlib.h"

extern char	**environ;

int	ft_env(t_word_list *list)
{
	char	**iter;

	if (list)
		perror(list->word->word);  // No such file or directory
	iter = environ;
	while (*iter)
		printf("%s\n", *iter++);
	return (0);
}
