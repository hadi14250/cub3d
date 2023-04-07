/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:15:41 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/10 19:37:31 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	length;
	int	i;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else
		length = 0;
	i = -1;
	while (str[++i] != '\0')
		length += ft_putchar(str[i]);
	return (length);
}
