/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:44:14 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:29:10 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	int				d;

	i = 0;
	d = 0;
	while (src[d] != '\0')
		d++;
	if (!dstsize || dstsize == 0)
		return (d);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (d);
}

/*int main()
{
	
	char src1[100] = "Hadi";
	char dst1[100] = "Okayy";
	char src2[100] = "Hadi";
	char dst2[100] = "Okayy";
	size_t mine = ft_strlcpy(dst1, src1, 5);
	size_t theirs = strlcpy(dst2, src2, 5);
	printf("it's %zu long and it says %s\n", mine, dst1);
	printf("it's %zu long and it says %s\n", theirs, dst2);
}*/
