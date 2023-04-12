/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:30:32 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 03:37:03 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlens(int ac, char **av, char *sep)
{
	int	i;
	int	j;
	int	b;

	b = 0;
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		b += j;
		i++;
	}
	b += (ft_strlen (sep) * ac) - ft_strlen (sep);
	return (b);
}

char	*ft_strsjoin(int ac, char **av, char *sep)
{
	int		i;
	int		b;
	int		j;
	int		d;
	char	*tmp;

	i = 0;
	tmp = malloc ((ft_strlens (ac, av, sep)) + 1);
	b = 0;
	while (++i < ac)
	{
		j = 0;
		d = 0;
		while (av[i][j] != '\0')
			tmp[b++] = av[i][j++];
		while (sep[d] != '\0')
			tmp[b++] = sep[d++];
	}
	tmp[b] = '\0';
	return (tmp);
}

/*#include <stdio.h>
int main (int ac, char **av)
{
	printf ("%s", ft_strsjoin (ac, av, "\n"));
}*/