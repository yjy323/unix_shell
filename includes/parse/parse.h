/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:16:46 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/24 17:37:36 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "data.h"

// get_ast_tree
void	parse(char *str, t_tree *ast);
void	tokenize(const char *str, t_token_list *lst_token);
void	lex(t_token_list *lst_token, t_token_list *lst_lex);
void	translate_env_in_node(t_node *node);
void	parse_tree(t_token_list *lst_token, t_tree *ast);

// valid
void	valid_syntax(t_token_list *lst);

#endif
