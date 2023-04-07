/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FIZZBUZZ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:22:29 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/29 15:28:02 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void FIZZBUZZ (int n)
{
	int i;
	
	i = 1;
	while (i <= n)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "FIZZBUZZ\n", 9);
		else if (i % 3 == 0)
			write(1, "FIZZ\n", 5);
		else if (i % 5 == 0)
			write(1, "BUZZ\n", 5);
		else if (i % 3 != 0 && i % 5 != 0)
		{
			ft_putnbr (i);
			write (1, "\n", 1);
		}
		i++;
	}
}

/*int main ()
{
	FIZZBUZZ(100);
}*/