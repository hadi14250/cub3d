/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:16:51 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 03:38:24 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int nb, char c)
{
	int			length;
	int			d;
	long long	nbr;
	char		res;

	length = 0;
	if (c == 'x')
		d = 87;
	if (c == 'X')
		d = 55;
	if (nb >= 16)
		length += ft_put_hex (nb / 16, c);
	nbr = nb % 16;
	if (nbr < 10)
		res = nbr + 48;
	if (nbr >= 10)
		res = nbr + d;
	length += ft_putchar(res);
	return (length);
}
