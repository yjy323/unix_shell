/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_execute.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/20 18:55:53 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_EXECUTE_H
# define TYPE_EXECUTE_H

# include <stdbool.h>

typedef struct s_pid_lst {
	int					pid;
	struct s_pid_list	*next;
}	t_pid_lst;

typedef struct s_cmd
{
	char		*exec_path;
	char		**args;
	bool		flag_first_cmd;
	bool		flag_last_cmd;
}	t_cmd;

typedef struct s_op
{
	int				fd[2];
	int				pre_fd[2];
}	t_op;

typedef struct s_compound
{
	struct s_cmd		*cmd;
	struct s_pid_lst	*cmd_pid_lst;
	char				*(**p_environ);
	struct s_op			*op;
}	t_compound;

#endif
