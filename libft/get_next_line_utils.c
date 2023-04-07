/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:07:15 by hakaddou          #+#    #+#             */
/*   Updated: 2022/06/14 21:42:10 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gl_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

int	gl_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = gl_strlen(s1);
	len2 = gl_strlen(s2);
	if (!len1 && !len2)
		return (0);
	str = ft_calloc(len1 + len2 + 1, 1);
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
