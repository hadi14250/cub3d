/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:19:11 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:26:52 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src1;
	char	*dst1;

	if (!dst && !src)
		return (0);
	i = 0;
	src1 = (char *)src;
	dst1 = (char *)dst;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
