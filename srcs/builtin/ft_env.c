/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:28:53 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/26 16:17:43 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"

int	ft_env(t_word_list *list)
{
	char	**iter;

	if (list)
		return (exception_handler(ENOCMD, "env", list->word->word, strerror(ENOENT)));
	iter = g_sh_variable.environment->env_array;
	while (*iter)
		printf("%s\n", *(iter++));
	return (SUCCESS);
}
