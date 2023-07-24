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

# define ERROR -1
# define ENOCMD 127

# include <errno.h>

typedef enum e_type {
	COMMAND,
	PIPELINE,
	REDIRECT,
	SPACE,
	WORD,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
}t_type;

typedef struct s_token {
	char			*word;
	t_type			type;
}t_token;

typedef struct s_node {
	t_token			*data;
	struct s_node	*parent;
	struct s_node	*left;
	struct s_node	*right;
}t_node;

typedef struct s_tree {
	t_node	*root;
}t_tree;

void	crash(char *message, int errnum);

#endif
