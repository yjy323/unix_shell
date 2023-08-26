/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:37:26 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/26 13:57:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <unistd.h>
# include <stdbool.h>
# include "utils.h"

/* Default Expander Buffer Size */
# define DEBS 1024

typedef struct s_expander {
	char	*istr;
	char	*pstr;
	char	*ostr;
	char	buffer[DEBS];
	size_t	buffer_idx;
	bool	isin_singlequote;
	bool	isin_doublequote;
}t_expander;

void	init_expander(t_expander *epd, char *istr);
void	add_expander_c(t_expander *epd, char c);
void	add_expander_str(t_expander *epd, char *str);
void	clear_expander_buffer(t_expander *epd);

#endif
