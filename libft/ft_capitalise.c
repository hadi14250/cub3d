/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:43:48 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 03:38:42 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalise(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= 32;
		if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == 32)
			str[i] -= 32;
		if (str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] != 32)
			str[i] += 32;
		i++;
	}
	return (str);
}
