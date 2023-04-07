/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:20:46 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/09 18:32:37 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_address(unsigned long long nb)
{
	int		length;
	int		nbr;
	char	res;

	length = 0;
	if (nb >= 16)
		length += ft_put_address (nb / 16);
	nbr = nb % 16;
	if (nbr < 10)
		res = nbr + 48;
	if (nbr >= 10)
		res = nbr + 87;
	length += ft_putchar(res);
	return (length);
}
