/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:27:50 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/10 22:21:53 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rect	init_rect(int x, int y, int width, int height)
{
	t_rect	rect;

	rect.x = x + 1;
	rect.y = y + 1;
	rect.width = width + 1;
	rect.height = height + 1;
	return (rect);
}

void	draw_rectangle(t_img *img, t_rect rect, int color)
{
	int	i;
	int	j;

	i = rect.x;
	j = rect.y;
	while (i < rect.x + rect.width)
	{
		while (j < rect.y + rect.height)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
		j = rect.y;
	}
}

// make re && make clean && clear && valgrind --leak-check=full ./cub3d map.cub
int main(int ac, char **av)
{
	t_cub		cub;

	ft_bzero(&cub, sizeof(cub));
	parse(ac, &cub, av[1]);
	init(&cub);
	print_cub(&cub);

	// parse_size(cub);
	cub.m_flag = 0;
	init_mlx_utils(&cub);
	raycasting(&cub);
	exit_cub(&cub, 0, "game finished successfully\n");
}
