/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 06:06:31 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 16:54:23 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>
#include <unistd.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"

int	ft_unset(t_word_list *list);

int	ft_unset(t_word_list *list)
{
	t_word_list			*iter;
	char				*name;
	t_bucket_contents	*bucket;
	t_environment		*environ;

	environ = g_sh_variable.environment;
	iter = list;
	while (iter)
	{
		name = iter->word->word;
		bucket = hash_search(iter->word->word, environ->env_table);
		if (bucket)
		{
			dispose_variable(bucket->data);
			hash_remove(name, environ->env_table);
			remove_export_env(name, environ->env_array);
		}
		iter = iter->next;
	}
	return (0);
}
