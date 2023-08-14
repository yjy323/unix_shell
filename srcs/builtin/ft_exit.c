/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:38:32 by jy_23             #+#    #+#             */
/*   Updated: 2023/08/11 22:35:33 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h";

int	ft_exit(t_word_list *list, int status)
{
	if (!list)
		exit(status);
	else
	{
		// valid numeric args, args count
		exit(ft_atoi(list->word));
	}
}
