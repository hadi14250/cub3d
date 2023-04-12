/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:56:46 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 03:38:54 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char		*tmp;

	if (n == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	tmp = malloc(n * size);
	if (tmp == NULL)
		return (tmp);
	ft_bzero(tmp, size * n);
	return (tmp);
}
