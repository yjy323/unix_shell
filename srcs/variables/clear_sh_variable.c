/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sh_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:35:16 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/23 18:37:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "variables.h"

void	clear_sh_variable(t_sh_variable *sh_variable);

void	clear_sh_variable(t_sh_variable *sh_variable)
{
	if (sh_variable->environment)
		free(sh_variable->environment);
	if (sh_variable->mwd)
		free(sh_variable->mwd);
}
