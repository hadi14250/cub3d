/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 04:09:37 by hakaddou          #+#    #+#             */
/*   Updated: 2022/06/14 21:30:21 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!len1 && !len2)
		return (0);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (0);
	str[0] = '\0';
	while (i < len1 + len2)
	{
		if (i < len1)
			str[i] = s1[i];
		if (i >= len1)
			str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
