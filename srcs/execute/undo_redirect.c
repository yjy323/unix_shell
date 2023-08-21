/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:58:41 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/21 17:20:12 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	undo_redirect(int save_stdin_fd, int save_stdout_fd)
{
	dup2(save_stdin_fd, STDIN_FILENO);
	dup2(save_stdout_fd, STDOUT_FILENO);
	close(save_stdin_fd);
	close(save_stdout_fd);
}
