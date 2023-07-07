/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:08:05 by juyyang           #+#    #+#             */
/*   Updated: 2023/01/17 20:25:54 by juyyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		size = 0;
	else if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!s || !dst || len < 0)
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(s))
		dst[i++] = s[start++];
	dst[i] = 0;
	return (dst);
}
