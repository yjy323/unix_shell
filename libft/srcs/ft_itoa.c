/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:59:26 by juyyang           #+#    #+#             */
/*   Updated: 2022/12/30 19:41:49 by juyyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calculate_size(long nbr)
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

char	*ft_itoa(int n)
{
	long	nbr;
	int		size;
	char	*str;

	nbr = n;
	size = calculate_size(nbr);
	if (n < 0)
		nbr *= -1;
	str = (char *)malloc(sizeof(char) * (size + 1));
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
