/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:01:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 16:30:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "libft.h"

void	*xmalloc(size_t bytes);
void	*xrealloc(void *ptr, size_t bytes);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);

void	*xmalloc(size_t bytes)
{
	void	*temp;

	temp = malloc(bytes);
	if (temp == 0)
	{
		printf("%s: cannot allocate %lu bytes", \
			"xmalloc", (unsigned long)bytes);
		exit(ENOMEM);
	}
	return (temp);
}

void	*xrealloc(void *ptr, size_t bytes)
{
	void	*temp;

	temp = xmalloc(bytes);
	ft_memmove(temp, ptr, bytes);
	free(ptr);
	return (temp);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s2 = (char *)xmalloc(sizeof(char) * (s1_len + 1));
	ft_memcpy(s2, (void *)s1, s1_len + 1);
	return (s2);
}

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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	new_str = (char *)xmalloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new_str[s1_len + i] = s2[i];
		i++;
	}
	new_str[s1_len + i] = 0;
	return (new_str);
}
