/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_environ_convention.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:47:05 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/26 19:16:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"
#include "libft.h"

int	valid_environ_convention(char *cmd, char *key);

int	valid_environ_convention(char *cmd, char *key)
{
	if (*key == '=')
		return (exception_handler(EGENRAL, cmd, key, INVARG));
	while (*key)
	{
		if (*key == '=')
			break ;
		else if (!(ft_isalnum(*key) || *key == '_'))
			return (exception_handler(EGENRAL, cmd, key, INVARG));
		key++;
	}
	return (SUCCESS);
}
