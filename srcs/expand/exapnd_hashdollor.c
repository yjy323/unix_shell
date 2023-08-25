/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exapnd_hashdollor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:54:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 20:19:09 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdbool.h>
#include "command.h"
#include "expand/expander.h"
#include "hashlib.h"
#include "variables.h"
#include "status.h"
#include "libft.h"

void		expand_hashdollor(t_expander *epd);
static void	expand_question(t_expander *epd);
static void	expand_env(t_expander *epd, t_environment *environ);

void	expand_hashdollor(t_expander *epd)
{
	if (ft_strncmp(epd->pstr, "$?", 2) == 0)
		expand_question(epd);
	else if (!ft_isalnum(*(epd->pstr + 1)))
	{
		add_expander_c(epd, '$');
		epd->pstr++;
	}
	else
		expand_env(epd, g_sh_variable.environment);
}

static void	expand_question(t_expander *epd)
{
	char	*str_exit_num;

	str_exit_num = ft_xstrdup("[exit code]");
	str_exit_num = ft_xitoa(g_sh_variable.status);
	add_expander_str(epd, str_exit_num);
	epd->pstr = epd->pstr + 2;
	free(str_exit_num);
}

static void	expand_env(t_expander *epd, t_environment *environ)
{
	char				*env_key;
	char				*skey;
	char				*ekey;
	char				*env_val;

	skey = epd->pstr;
	ekey = epd->pstr + 1;
	while (ft_isalnum(*ekey))
		ekey++;
	env_key = ft_xsubstr(skey, 1, ekey - skey - 1);
	env_val = hash_search_variable_value(env_key, environ->env_table);
	if (env_val)
		add_expander_str(epd, env_val);
	epd->pstr = epd->pstr + ft_strlen(env_key) + 1;
	free(env_key);
}
