/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 03:05:13 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:30:13 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*tmp;
	size_t		i;

	if (!s || len == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (ft_strlen(s) < len)
		tmp = (char *)malloc(ft_strlen(&s[start] + 1));
	else
		tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (0);
	while (start < ft_strlen(s) && i < len)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
