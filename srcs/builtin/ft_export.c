/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:44:47 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 23:16:36 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

#include "builtin.h"
#include "minishell.h"
#include "status.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "utils.h"

int			ft_export(t_word_list *list);
static int	ft_export_without_args(t_hash_table *table);
static int	ft_export_word(char *word, t_environment *environ);
static int	ft_export_word_appned(char *name,
				char *value, t_environment *environ);
static char	*get_variable(char *word,
				char **p_name, char **p_value, int *exp_append);

int	ft_export(t_word_list *list)
{
	int				status;
	t_environment	*environ;

	environ = g_sh_variable.environment;
	status = SUCCESS;
	if (list)
	{
		while (list)
		{
			status = ft_export_word(list->word->word, environ);
			list = list->next;
		}
	}
	else
		status = ft_export_without_args(environ->env_table);
	return (status);
}

static int	ft_export_without_args(t_hash_table *table)
{
	int					i;
	t_bucket_contents	*bucket;
	t_variable			*var;

	i = 0;
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
	return (SUCCESS);
}

static int	ft_export_word(char *word, t_environment *environ)
{
	char	*name;
	char	*value;
	int		exp_append;

	if (valid_environ_convention("export", word))
		return (EGENRAL);
	exp_append = 0;
	name = 0;
	value = 0;
	if (get_variable(word, &name, &value, &exp_append) == 0)
		name = ft_xstrdup(word);
	if (exp_append)
		ft_export_word_appned(name, value, environ);
	else
	{
		if (value)
			update_export_env(name, value, environ, V_CREATE);
		bind_variable(name, value, environ->env_table, V_CREATE);
	}
	free(name);
	free(value);
	return (SUCCESS);
}

static int	ft_export_word_appned(char *name,
				char *value, t_environment *environ)
{
	t_bucket_contents	*bucket;
	t_variable			*entry;
	char				*temp;

	temp = value;
	bucket = hash_search(name, environ->env_table);
	if (bucket)
	{
		entry = (t_variable *)bucket->data;
		if (entry && entry->value)
			value = ft_xstrjoin(entry->value, value);
		else
			value = ft_xstrdup(value);
		free(temp);
	}
	if (value)
		update_export_env(name, value, environ, V_CREATE);
	bind_variable(name, value, environ->env_table, V_CREATE);
	return (SUCCESS);
}

static char	*get_variable(char *word,
				char **p_name, char **p_value, int *p_exp_append)
{
	int	idx;

	idx = 0;
	while (word[idx])
	{
		if (word[idx] == '=')
		{
			word[idx] = 0;
			*p_name = ft_xstrdup(word);
			*p_value = ft_xstrdup(word + idx + 1);
			word[idx] = '=';
			break ;
		}
		else if (word[idx] == '+' && word[idx + 1] == '=')
		{
			word[idx] = 0;
			*p_name = ft_xstrdup(word);
			*p_value = ft_xstrdup(word + idx + 2);
			word[idx] = '+';
			*p_exp_append = 1;
			break ;
		}
		idx++;
	}
	return (*p_name);
}
