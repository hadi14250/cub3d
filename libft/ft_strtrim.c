/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:25:38 by hakaddou          #+#    #+#             */
/*   Updated: 2022/06/14 23:01:18 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen((char *)s1);
	while (*s1 && ft_strrchr(set, s1[i]))
		i--;
	res = ft_substr(s1, 0, i + 1);
	return (res);
}

int main ()
{
	char str[] = "zxzxo x Jensen showered today xxz ";
	char set[] = "zx o";
	char *trim = ft_strtrim(str, set);
	printf("%s\n", trim);
}