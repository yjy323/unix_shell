/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:07:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 13:42:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "stdbool.h"
# include "command.h"
# include "variables.h"
# include "lex.h"
# include "utils.h"

typedef struct s_parser {
	t_command	*root;
	t_command	*cur_command;
}t_parser;

t_command	*parse(char *str, t_sh_variable *sh_variable);
bool		syntex_check(t_lex_list *lex_list);

void		do_here_doc(char *filename, char *limiter, t_environment *environ);

#endif
