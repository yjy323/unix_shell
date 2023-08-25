/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:21:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 19:58:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "variables.h"
# include "expand/expander.h"

t_word_list	*expand_words(t_word_list *list);
void		expand_word(t_word_desc *word);
t_word_list	*word_desc_split(t_word_desc *word_desc);
void		remove_quote_nulls(t_word_list *list);

void		expand_hashdollor(t_expander *epd);
char		*expand_for_heredoc(char *str);

#endif
