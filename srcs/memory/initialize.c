/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:44:24 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 11:54:06 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/type.h"
#include "../../includes/execute.h"
#include "../../libft/includes/libft.h"

t_cmd		*init_cmd(char *envp[]);
static char	**extract_path(char *envp[]);

t_cmd	*init_cmd(char *envp[])
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		crash(errno);
	cmd->envp = envp;
	cmd->path = extract_path(envp);
	cmd->sub_pid_head = malloc(sizeof(t_pid_list));
	cmd->flag_first_cmd = true;
	cmd->flag_last_cmd = false;
	return (cmd);
}

static char	**extract_path(char *envp[])
{
	char	*envp_path;
	size_t	i;

	i = 0;
	envp_path = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			envp_path = envp[i];
			break ;
		}
		i++;
	}
	return (ft_split(ft_strchr(envp_path, '=') + 1, ':'));
}
