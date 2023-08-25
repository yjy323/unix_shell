/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:40:44 by juyyang           #+#    #+#             */
/*   Updated: 2023/01/17 20:25:54 by juyyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!s2)
		return (0);
	ft_memcpy(s2, (void *)s1, s1_len + 1);
	return (s2);
}
