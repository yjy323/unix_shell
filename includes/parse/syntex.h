/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:58:22 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 17:36:42 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTEX_H
# define SYNTEX_H

# include <stdbool.h>
# include "parse/lex_list.h"

int	syntex_check(t_lex_list *pre, t_lex_list *cur);

#endif