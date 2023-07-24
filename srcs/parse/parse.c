/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:35:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 18:49:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	parse(char *str, t_tree *ast);

void	parse(char *str, t_tree *ast)
{
	t_token_list	lst_token;
	t_token_list	lst_lex;

	init_token_list(&lst_token);
	init_token_list(&lst_lex);
	tokenize(str, &lst_token);
	lex(&lst_token, &lst_lex);
	valid_syntax(&lst_lex);
	parse_tree(&lst_lex, ast);

	clear_tree(ast);
}
