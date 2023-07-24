/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:08:29 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/20 22:50:55 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_PARSE_H
# define TYPE_PARSE_H

# include "../common.h"

typedef struct s_token_list {
	t_node	*front;
	t_node	*rear;
}t_token_list;


#endif

