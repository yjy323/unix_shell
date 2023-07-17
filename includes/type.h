/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/17 20:02:00 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdbool.h>

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

typedef struct s_token_list {
	t_node	*front;
	t_node	*rear;
}t_token_list;

typedef struct s_tree {
	t_node	*root;
}t_tree;

typedef struct s_pid_list {
	int					pid;
	struct s_pid_list	*next;
}	t_pid_list;

typedef struct s_cmd
{
	char		*cmd_path;
	char		**args;
	char		**envp;
	char		**path;
	t_pid_list	*sub_pid_head;
	int			fd[2];
	int			pre_fd[2];
	bool		flag_first_cmd;
	bool		flag_last_cmd;
}	t_cmd;

// token
t_token	*get_token(void);
void	free_token(t_token *token);
t_token	*get_token_with_data(const char *word, t_type type);

// node
t_node	*getnode(t_token *data);
void	free_node(t_node *node);

// list
void	init_token_list(t_token_list *lst);
bool	isempty_token_list(t_token_list *lst);
void	clear_token_list(t_token_list *lst);
void	push_front(t_token_list *lst, t_node *node);
void	push_back(t_token_list *lst, t_node *node);
t_node	*pop_front(t_token_list *lst);
t_node	*pop_back(t_token_list *lst);

// tree
void	init_tree(t_tree *tree);
void	clear_tree(t_tree *tree);
void	add_lchild(t_node *parent, t_node *child);
void	add_rchild(t_node *parent, t_node *child);
void	add_parent_for_lchild(t_tree *tree, t_node *parent, t_node *child);
void	add_parent_for_rchild(t_tree *tree, t_node *parent, t_node *child);

#endif
