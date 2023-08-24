/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:11:06 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 13:42:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "hashlib.h"
#include "variables.h"
#include "expand/expand.h"

void	do_here_doc(char *filename, char *limiter, t_environment *environ)
{
	int		fd;
	char	*line;
	char	*oline;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (ft_strlen(line) == ft_strlen(limiter)
			&& !ft_strncmp(line, limiter, ft_strlen(line)))
			break ;
		// line = expand(line) & free(old_line)
		oline = line;
		line = expand_for_heredoc(line, environ);
		free(oline);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
}
