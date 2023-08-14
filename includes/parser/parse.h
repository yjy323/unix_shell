/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:07:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/11 16:40:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "stdbool.h"
# include "common/common.h"
# include "lex.h"

typedef struct s_parser {
	t_command	*root;
	t_command	*cur_command;
}t_parser;

t_command	*parse(char *str);
bool		syntex_check(t_lex_list *lex_list);

#endif