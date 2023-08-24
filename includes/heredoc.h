/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:16:13 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/24 13:43:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "variables.h"
# include "parser/lex.h"

void	do_here_doc(char *filename, char *limiter, t_environment *environ);
void	expand_heredoc(t_lex_list *list, t_sh_variable *sh_variable);

#endif
