/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadikaddoura <hadikaddoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:27:50 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/15 23:28:34 by hadikaddour      ###   ########.fr       */
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

void	init_consts(t_cub *cub)
{
	cub->player.fov = FOV_ANGLE * (PI / 180);
	cub->player.dist_proj_plane = ((WINDOW_WIDTH / 2)
			/ tan(cub->player.fov / 2));
	cub->player.mid_ray = (NUM_RAYS / 2) - 1;
	init_button_nums(cub->control_box.buttons);
	get_button_txt(cub->control_box.buttons);
}

// make re && make clean && clear && valgrind --leak-check=full ./cub3d map.cub
int	main(int ac, char **av)
{
	t_cub		cub;

	ft_bzero(&cub, sizeof(cub));
	parse(ac, &cub, av[1]);
	init(&cub);
	init_consts(&cub);
	init_mlx_utils(&cub);
	raycasting(&cub);
	exit_cub(&cub, 0, "game finished successfully\n");
}
