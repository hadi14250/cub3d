/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:19:56 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/08 20:43:38 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*res;
	int		len;
	long	n;

	n = nb;
	len = ft_nblen(n);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		res[len] = 48 + (n % 10);
		n /= 10;
		len--;
	}
	return (res);
}
