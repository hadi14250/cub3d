/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:18:57 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/09 18:30:20 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list ptr, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar (va_arg (ptr, int));
	else if (c == 's')
		length += ft_putstr (va_arg (ptr, char *));
	else if (c == 'x' || c == 'X')
		length += ft_put_hex (va_arg(ptr, unsigned int), c);
	else if (c == 'd' || c == 'i')
		length += ft_putnbr (va_arg(ptr, int));
	else if (c == 'p')
	{
		length += ft_putstr ("0x");
		length += ft_put_address (va_arg (ptr, unsigned long long));
	}
	else if (c == 'u')
		length += ft_putnbr_u(va_arg (ptr, unsigned int));
	else
		length += ft_putchar (c);
	return (length);
}
