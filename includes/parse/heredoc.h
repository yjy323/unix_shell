/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:16:13 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 19:56:10 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "variables.h"
# include "parse/lex.h"

int		take_heredoc(t_lex_list *cur, int heredoc_num);

#endif
