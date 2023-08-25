/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 04:17:03 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/25 20:05:42 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

# include <stdbool.h>
# include <unistd.h>
# include "hashlib.h"

# define V_NOCREATE 0
# define V_CREATE 1

typedef struct s_sh_variable	t_sh_variable;
typedef struct s_variable		t_variable;
typedef struct s_environment	t_environment;

typedef struct s_sh_variable {
	char			*temp_dir_path;
	int				status;
	t_environment	*environment;
}t_sh_variable;

typedef struct s_variable {
	char	*name;
	char	*value;
}	t_variable;

typedef struct s_environment{
	size_t			array_size;
	char			**env_array;
	t_hash_table	*env_table;
}	t_environment;

void			clear_sh_variable();
void			init_sh_variable();
t_variable		*bind_variable(char *name, char *value, t_hash_table *table, int flag);
t_variable		*bind_variable(char *name,
					char *value, t_hash_table *table, int flag);
t_variable		*create_variable(char *name, char *value);
void			dispose_variable(t_variable *entry);
char			**update_export_env(char *name,
					char *value, t_environment *environ, int flag);
char			**remove_export_env(char *name, char **export_env);
int				find_export_env(char *name, char **export_env);
t_environment	*create_environmet_variable(char **initial_environ);

#endif
