/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:04:49 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:27:01 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	size_t				d;
	unsigned char		*dst1;
	const unsigned char	*src1;

	i = 0;
	d = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (src < dst)
		while (i++ < len)
			dst1[len - i] = src1[len - i];
	else
	{
		while (d < len)
		{
			dst1[d] = src1[d];
			d++;
		}
	}
	return (dst1);
}
