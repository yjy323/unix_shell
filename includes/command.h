/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:20:24 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/27 15:21:57 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define W_HASDOLLAR 1
# define W_QUOTED 2
# define W_DQUOTED 524288

typedef enum e_command_type		t_command_type;
typedef struct s_command		t_command;
typedef struct s_simple_com		t_simple_com;
typedef struct s_connection		t_connection;
typedef struct s_word_list		t_word_list;
typedef struct s_redirect_list	t_redirect_list;
typedef struct s_redirect		t_redirect;
typedef struct s_word_desc		t_word_desc;

typedef enum e_command_type {
	cm_simple,
	cm_connection,
	cm_redirect
}t_command_type;

typedef struct s_command {
	t_command_type		type;
	t_simple_com		*simple;
	t_connection		*connection;
}t_command;

typedef struct s_simple_com {
	t_word_list		*words;
	t_redirect_list	*redirects;
}t_simple_com;

typedef struct s_connection {
	t_command	*first;
	t_command	*second;
	char		*word;
}t_connection;

typedef struct s_word_list {
	t_word_desc			*word;
	struct s_word_list	*next;
}t_word_list;

typedef struct s_redirect_list {
	t_redirect				*redirect;
	struct s_redirect_list	*next;
}t_redirect_list;

typedef struct s_redirect {
	char	*word;
	char	*filename;
	int		fd;
}t_redirect;

typedef struct s_word_desc {
	char	*word;
	int		flag;
}t_word_desc;

/* command */
void				init_command(t_command *command);
t_command			*get_command(void);
void				clear_command(t_command *command);
void				free_command(t_command *command);

/* simple_com */
void				init_simple_com(t_simple_com *simple_com);
t_simple_com		*get_simple_com(void);
void				clear_simple_com(t_simple_com *simple_com);
void				free_simple_com(t_simple_com *simple_com);

/* connection */
void				init_connection(t_connection *connection);
t_connection		*get_connection(void);
void				clear_connection(t_connection *connection);
void				free_connection(t_connection *connection);

/* word_list */
void				init_word_list(t_word_list *word_list);
t_word_list			*get_word_list(void);
void				free_word_list(t_word_list *word_list);
void				push_word_list(t_word_list **word_list, t_word_desc *word);
t_word_desc			*pop_word_list(t_word_list **word_list);

/* redirect_list */
void				init_redirect_list(t_redirect_list *redirect_list);
t_redirect_list		*get_redirect_list(void);
void				free_redirect_list(t_redirect_list *redirect_list);
void				push_redirect_list(\
						t_redirect_list **redirect_list, \
						t_redirect *redirect);
t_redirect			*pop_redirect_list(t_redirect_list **redirect_list);

/* redirect */
void				init_redirect(t_redirect *redirect);
t_redirect			*get_redirect(void);
void				clear_redirect(t_redirect *redirect);
void				free_redirect(t_redirect *redirect);

/* word_desc */
void				init_word_desc(t_word_desc *word_desc);
t_word_desc			*get_word_desc(void);
void				clear_word_desc(t_word_desc *word_desc);
void				free_word_desc(t_word_desc *word_desc);

#endif
