/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:31:35 by hakaddou          #+#    #+#             */
/*   Updated: 2022/06/14 17:08:47 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		b = 0;
		while (haystack[i + b] == needle[b] && (i + b < len))
		{
			b++;
			if (needle[b] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
