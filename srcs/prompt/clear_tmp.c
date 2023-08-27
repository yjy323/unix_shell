/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:04:55 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 21:00:11 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>

#include "libft.h"

#include "status.h"
#include "utils.h"

int			clear_tmp(char *tmp_path);
static bool	is_tmp_file(char *file);

int	clear_tmp(char *tmp_path)
{
	DIR				*dir_ptr;
	struct dirent	*file;
	char			*filename;

	dir_ptr = opendir(tmp_path);
	if (!dir_ptr)
		return (exception_handler(EGENRAL, tmp_path, 0, 0));
	file = readdir(dir_ptr);
	while (file)
	{
		filename = ft_xstrjoin(tmp_path, file->d_name);
		if (is_tmp_file(filename) && unlink(filename) == -1)
		{
			free(filename);
			return (exception_handler(EGENRAL, file->d_name, 0, 0));
		}
		else
			free(filename);
		file = readdir(dir_ptr);
	}
	if (closedir(dir_ptr))
		return (exception_handler(EGENRAL, tmp_path, 0, 0));
	return (SUCCESS);
}

bool	is_tmp_file(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (extension
		&& ft_strncmp(extension, ".tmp", ft_strlen(extension) + 1) == 0)
		return (true);
	else
		return (false);
}
