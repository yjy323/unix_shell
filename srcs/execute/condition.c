/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:51:28 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/17 12:30:35 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../libft/includes/libft.h"

bool	is_single_command(t_node *head);
bool	is_last_command(t_node *head);
bool	is_sequential_cmd(t_type type);
bool	is_asynchronous_cmd(t_type type);
bool	is_builtin(char *cmd_name);

bool	is_single_command(t_node *head)
{
	if (head->data->type != PIPELINE)
		return (true);
	else
		return (false);
}

bool	is_last_command(t_node *node)
{
	if (!node->parent)
		return (true);
	else
		return (false);
}

bool	is_sequential_cmd(t_type type)
{
	if (type == PIPELINE)
		return (false);
	return (true);
}

bool	is_asynchronous_cmd(t_type type)
{
	if (type == PIPELINE)
		return (false);
	return (true);
}

bool	is_builtin(char *cmd_name)
{
	size_t	len;

	return (false);
	len = ft_strlen(cmd_name);
	if (!ft_strncmp(cmd_name, "cd", len)
		|| !ft_strncmp(cmd_name, "echo", len)
		|| !ft_strncmp(cmd_name, "env", len)
		|| !ft_strncmp(cmd_name, "exit", len)
		|| !ft_strncmp(cmd_name, "export", len)
		|| !ft_strncmp(cmd_name, "pwd", len)
		|| !ft_strncmp(cmd_name, "unset", len))
		return (true);
	return (false);
}
