/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:59:19 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/10 17:19:20 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*free_null(void *ptr)
{
	if (!ptr)
		return (NULL);
	free(ptr);
	return (NULL);
}

void	free_split(char ***split)
{
	int		i;
	char	**to_free;

	to_free = *split;
	i = -1;
	if (!to_free)
		return ;
	while (to_free[++i])
		to_free[i] = free_null(to_free[i]);
	*split = free_null(to_free);
}

int	ft_array_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	*callocer(int size, int block, t_cub *cub)
{
	void	*ptr;

	ptr = ft_calloc(block, size);
	if (!ptr)
		exit_cub(cub, 1, "Error\nmemory allocation failed");
	return (ptr);
}

unsigned long	rgb_to_hex(int red, int green, int blue, t_cub *cub)
{
	unsigned long	temp;

	if (red > 255 || green > 255 || blue > 255
		|| red < 0 || green < 0 || blue < 0)
		cub->color_flag = true;
	temp = (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
	return (temp);
}
