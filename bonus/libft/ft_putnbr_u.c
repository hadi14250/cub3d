/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:17:37 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/09 18:35:26 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int		length;
	char	c;

	length = 0;
	if (nb == 2147483648)
		return (length += ft_putstr("2147483648"));
	if (nb >= 10)
		length += ft_putnbr (nb / 10);
	c = (nb % 10) + 48;
	length += ft_putchar(c);
	return (length);
}
