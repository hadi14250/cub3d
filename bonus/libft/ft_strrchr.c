/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 02:53:36 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/22 19:42:28 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i);
		i--;
	}
	return (0);
}
