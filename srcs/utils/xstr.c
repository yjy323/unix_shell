/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:57:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/27 21:00:51 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "utils.h"

char		*ft_xstrdup(const char *s1);
char		*ft_xsubstr(const char *s, unsigned int start, size_t len);
char		*ft_xstrjoin(const char *s1, const char *s2);
char		*ft_xitoa(int n);
static int	calculate_size(long nbr);

char	*ft_xstrdup(const char *s1)
{
	char	*s2;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s2 = (char *)xmalloc(sizeof(char) * (s1_len + 1));
	ft_memcpy(s2, (void *)s1, s1_len + 1);
	return (s2);
}

char	*ft_xsubstr(const char *s, unsigned int start, size_t len)
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
	dst = (char *)xmalloc(sizeof(char) * (size + 1));
	if (!s || !dst || len < 0)
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(s))
		dst[i++] = s[start++];
	dst[i] = 0;
	return (dst);
}

char	*ft_xstrjoin(const char *s1, const char *s2)
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

char	*ft_xitoa(int n)
{
	long	nbr;
	int		size;
	char	*str;

	nbr = n;
	size = calculate_size(nbr);
	if (n < 0)
		nbr *= -1;
	str = (char *)xmalloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = 0;
	while (nbr)
	{
		str[size - 1] = nbr % 10 + '0';
		nbr /= 10;
		size--;
	}
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str[0] = '-';
	return (str);
}

static int	calculate_size(long nbr)
{
	int		size;

	if (nbr <= 0)
	{
		size = 1;
		nbr *= -1;
	}
	else
		size = 0;
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
