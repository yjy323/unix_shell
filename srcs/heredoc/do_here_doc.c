/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:11:06 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/23 14:19:44 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

void	do_here_doc(char *filename, char *limiter)
{
	int		fd;
	char	*line;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (ft_strlen(line) == ft_strlen(limiter)
			&& !ft_strncmp(line, limiter, ft_strlen(line)))
			break ;
		//  line = expand(line) & free(old_line)
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
}
