/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:12:21 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:26:34 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	size_t				i;
	unsigned char		cu;

	cu = (unsigned char)c;
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == cu)
			return ((void *)str);
		i++;
		str++;
	}
	return (NULL);
}
