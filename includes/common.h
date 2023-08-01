/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:20:24 by jy_23             #+#    #+#             */
/*   Updated: 2023/07/24 17:28:36 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

typedef enum e_command_type { cm_simple, cm_connection }t_command_type;

typedef struct s_word_list {
	struct s_word_list	*next;
	char				*word;
}t_word_list;

typedef struct s_redirect {
	char	*word;
	char	*filename;
}t_redirect;

typedef struct s_simple_com {
	t_word_list	*words;
	t_redirect	*redirect;		
}t_simple_com;

typedef struct s_command {
	t_command_type		type;
	t_simple_com		*simple;
	struct s_command	*first;
	struct s_command	*second;
}t_command;

#endif
