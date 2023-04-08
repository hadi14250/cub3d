/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:25:12 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:28:27 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		d;
	char	*tmp;
	int		size;

	i = 0;
	d = 0;
	size = ft_strlen((char *)s1);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[d] = s1[i];
		i++;
		d++;
	}
	tmp[d] = '\0';
	return (tmp);
}
