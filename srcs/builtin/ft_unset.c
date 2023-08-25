/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 06:06:31 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 17:09:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"

int	ft_unset(t_word_list *list, t_environment *environ);

int	ft_unset(t_word_list *list, t_environment *environ)
{
	t_word_list			*iter;
	char				*name;
	t_bucket_contents	*bucket;

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
			if (bucket->key)
				free(bucket->key);
			free(bucket);
		}
		iter = iter->next;
	}
	return (0);
}
