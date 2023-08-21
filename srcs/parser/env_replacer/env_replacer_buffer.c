/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_replacer_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:38:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:35:52 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "command.h"
#include "parser/env_replace.h"
#include "libft.h"

void	add_str_env_replacer(t_env_replacer *env_replacer, const char *str);
void	add_char_env_replacer(t_env_replacer *env_replacer, char c);
void	clear_buffer(t_env_replacer *env_replacer);

void	add_str_env_replacer(t_env_replacer *env_replacer, const char *str)
{
	if (!str)
		return ;
	while (*str)
		add_char_env_replacer(env_replacer, *str++);
}

void	add_char_env_replacer(t_env_replacer *env_replacer, const char c)
{
	env_replacer->buffer[env_replacer->buffer_ind++] = c;
	if (env_replacer->buffer_ind == BUFFER_SIZE)
		clear_buffer(env_replacer);
}

void	clear_buffer(t_env_replacer *env_replacer)
{
	char	*new_res;

	new_res = ft_strjoin(env_replacer->res, env_replacer->buffer);
	if (!new_res)
		crash(ENOMEM, "");
	free(env_replacer->res);
	env_replacer->res = new_res;
	ft_memset(env_replacer->buffer, 0, BUFFER_SIZE);
	env_replacer->buffer_ind = 0;
}
