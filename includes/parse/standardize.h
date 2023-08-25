/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standardize.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:31:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/24 17:34:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STANDARDIZE_H
# define STANDARDIZE_H

# include "parse/lex_list.h"
# include "variables.h"

int	standardize(t_lex_list *list, t_sh_variable *sh_variable);

#endif