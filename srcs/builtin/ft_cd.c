/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:28:05 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/29 12:35:40 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "status.h"
#include "builtin.h"
#include "command.h"
#include "hashlib.h"
#include "variables.h"
#include "utils.h"

int					ft_cd(t_word_list *list);
static int			set_pwd(t_environment *environ);
static int			set_oldpwd(t_environment *environ);
static t_word_list	*make_arguemnt(char *name, char *value);

int	ft_cd(t_word_list *list)
{
	char	*env_home;
	char	*dir_name;

	if (list)
		dir_name = list->word->word;
	else
	{
		env_home = hash_search_variable_value("HOME",
				g_sh_variable.environment->env_table);
		if (!env_home)
			return (exception_handler(EGENRAL, "cd", 0, INVHOME));
		dir_name = env_home;
	}
	if (chdir(dir_name) == -1)
		return (exception_handler(EGENRAL, "cd", dir_name, 0));
	set_oldpwd(g_sh_variable.environment);
	set_pwd(g_sh_variable.environment);
	return (SUCCESS);
}

static int	set_oldpwd(t_environment *environ)
{
	t_bucket_contents	*bucket;
	t_word_list			*argument;

	argument = 0;
	bucket = hash_search("PWD", environ->env_table);
	if (bucket && hash_search("OLDPWD", environ->env_table))
	{
		argument = make_arguemnt("OLDPWD", ((t_variable *)bucket->data)->value);
		ft_export(argument);
	}
	else
	{
		argument = make_arguemnt("OLDPWD", 0);
		ft_export(argument);
		remove_export_env("OLDPWD", environ->env_array);
	}
	if (argument)
		free_word_list(argument);
	return (SUCCESS);
}

static int	set_pwd(t_environment *environ)
{
	char				*value;
	t_bucket_contents	*bucket;
	t_word_list			*argument;

	value = getcwd(0, 0);
	bucket = hash_search("PWD", environ->env_table);
	if (bucket)
	{
		argument = make_arguemnt("PWD", value);
		ft_export(argument);
		free_word_list(argument);
	}
	free(value);
	return (SUCCESS);
}

static t_word_list	*make_arguemnt(char *name, char *value)
{
	t_word_list	*word_list;
	t_word_desc	*word_desc;
	char		*var;
	char		*del;

	word_list = get_word_list();
	word_desc = get_word_desc();
	if (value)
	{
		var = ft_xstrjoin("=", value);
		del = var;
		var = ft_xstrjoin(name, var);
		free(del);
	}
	else
		var = ft_xstrdup(name);
	word_desc->word = var;
	word_list->word = word_desc;
	return (word_list);
