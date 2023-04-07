/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 02:06:46 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:28:52 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		d;

	i = ft_strlen(dst);
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	d = 0;
	while (src[d] != '\0' && i < dstsize - 1)
		dst[i++] = src[d++];
	dst[i] = '\0';
	return (ft_strlen(&src[d]) + ft_strlen(dst));
}
