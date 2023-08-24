/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:44:47 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 15:07:49 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "libft.h"
#include "utils.h"

int			ft_export(t_word_list *list, t_environment *environ);
static int	ft_export_without_args(t_hash_table *table);
static int	ft_export_word(char *word, t_environment *environ);
static int	ft_export_word_appned(char *name, char *value, t_environment *environ);
static int	get_variable(char *word, char **p_name, char **p_value, int *exp_append);

int	ft_export(t_word_list *list, t_environment *environ)
{
	int	status;

	status = 0;
	
	if (list)
	{
		if (list->word->word && *list->word->word == '-')
			return (1);
		while (list)
		{
			ft_export_word(list->word->word, environ);
			list = list->next;
		}
	}
	else
		status = ft_export_without_args(environ->env_table);
	return (status);
}

static int	ft_export_without_args(t_hash_table *table)
{
	int	i = 0;

	t_bucket_contents	*bucket;
	t_variable			*var;
	while (i < table->nbuckets)
	{
		if (table->bucket_array[i])
		{
			bucket = table->bucket_array[i];
			while (bucket)
			{
				var = (t_variable *)bucket->data;
				if (var->value)
					printf("declare -x %s=\"%s\"\n", var->name, var->value);
				else
					printf("declare -x %s\n", var->name);
				bucket = bucket->next;
			}
		}
		i++;
	}
	return (0);
}

static int	ft_export_word(char *word, t_environment *environ)
{
	char	*name;
	char	*value;
	int		exp_append;

	exp_append = 0;
	name = 0;
	value = 0;
	get_variable(word, &name, &value, &exp_append);
	if (exp_append)
		ft_export_word_appned(name, value, environ);
	else
	{
		if (value)
			update_export_env(name, value, environ, V_CREATE);
		bind_variable(name, value, environ->env_table, V_CREATE);
	}
	return (0);
}

static int	ft_export_word_appned(char *name, char *value, t_environment *environ)
{
	t_bucket_contents	*bucket;
	t_variable			*entry;
	char		*temp;

	temp = value;
	bucket = hash_search(name, environ->env_table);
	if (bucket)
	{
		entry = (t_variable *)bucket->data;
		if (entry && entry->value)
			value = ft_strjoin(entry->value, value);
		else
			value = ft_strdup(value);
		free(temp);
	}
	if (value)
		update_export_env(name, value, environ, V_CREATE);
	bind_variable(name, value, environ->env_table, V_CREATE);
	return (0);
}

static int	get_variable(char *word, char **p_name, char **p_value, int *p_exp_append)
{
	int	idx;

	idx = 0;
	while (word[idx])
	{
		if (word[idx] == '=')
		{
			word[idx] = 0;
			*p_name = ft_strdup(word);
			*p_value = ft_strdup(word + idx + 1);
			word[idx] = '=';
			break ;
		}
		else if (word[idx] == '+' && word[idx + 1] == '=')
		{
			word[idx] = 0;
			*p_name = ft_strdup(word);
			*p_value = ft_strdup(word + idx + 2);
			word[idx] = '+';
			*p_exp_append = 1;
			break ;
		}
		idx++;
	}
	if (!*p_name)
		*p_name = ft_strdup(word);
	return (*p_exp_append);
}
