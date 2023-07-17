/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:22:19 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 12:27:25 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../libft/includes/libft.h"

char	**set_cmd_args(t_node *node);
char	*set_cmd_path(char *cmd, char **path);

char	**set_cmd_args(t_node *node)
{
	char	**args;
	t_node	*iter;
	int		cnt;
	int		i;

	iter = node;
	cnt = 0;
	while (iter)
	{
		iter = iter->right;
		cnt++;
	}
	args = malloc(sizeof(char *) * (cnt + 1));
	if (!args)
		crash(errno);
	args[cnt] = NULL;
	i = 0;
	while (i < cnt)
	{
		args[i] = ft_strdup(node->data->word);
		if (!args[i++])
			crash(errno);
		node = node->right;
	}
	return (args);
}

char	*set_cmd_path(char *cmd, char **path)
{
	char	*dir_cmd;
	char	*path_cmd;
	char	**iter;

	iter = path;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	dir_cmd = ft_strjoin("/", cmd);
	if (!dir_cmd)
		crash(errno);
	while (*iter)
	{
		path_cmd = ft_strjoin(*iter, dir_cmd);
		if (!path_cmd)
			crash(errno);
		else if (access(path_cmd, F_OK) == 0)
			break ;
		else
			free(path_cmd);
		iter++;
	}
	free(dir_cmd);
	return (path_cmd);
}
