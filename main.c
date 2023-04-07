/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:27:50 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/07 15:38:45 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*init_struct( void )
{
	t_cub	*cub;

	cub = calloc(sizeof(t_cub), 1);
	if (!cub)
	{
		printf("struct allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return (cub);
}

t_rect	init_rect(int x, int y, int width, int height)
{
	t_rect	rect;

	rect.x = x + 1;
	rect.y = y + 1;
	rect.width = width + 1;
	rect.height = height + 1;
	return (rect);
}

// void	draw_rectangle(t_img *img, t_rect rect, int color)
// {
// 	int	i;
// 	int	j;

// 	i = rect.x;
// 	j = rect.y;
// 	while (i < rect.x + rect.width)
// 	{
// 		while (j < rect.y + rect.height)
// 		{
// 			my_mlx_pixel_put(img, i, j, color);
// 			j++;
// 		}
// 		i++;
// 		j = rect.y;
// 	}
// }

int main(int ac, char **av)
{
	t_cub	cub;
	ft_bzero(&cub, sizeof(cub));
	parse(ac, &cub, av[1]);

	init(&cub);

	init_mlx_utils(&cub);
	cub.color_buffer = calloc(sizeof(int) * WINDOW_WIDTH , WINDOW_HEIGHT);
	cub.tex = calloc(sizeof(int) * WINDOW_WIDTH , WINDOW_HEIGHT);
	raycasting(&cub);
}
