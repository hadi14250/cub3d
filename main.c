/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:27:50 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/23 20:24:11 by hakaddou         ###   ########.fr       */
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

void	set_original_controls(t_cub *cub)
{
	t_original_settings	original;
	original.gun = cub->gun;
	original.sky_color = cub->ceiling;
	original.floor_color = cub->floor;
	original.mini_map_bg_color = cub->player.map3d.map_background_color;
	original.mini_map_wall_color = cub->player.map3d.map_wall_color;
	original.mini_map_ray_color = cub->player.map3d.map_ray_color;
	cub->control_box.original_controls = original;
}

void	init_consts(t_cub *cub)
{
	cub->player.fov = FOV_ANGLE * (PI / 180);
	cub->player.dist_proj_plane = ((WINDOW_WIDTH / 2)
			/ tan(cub->player.fov / 2));
	cub->player.mid_ray = (NUM_RAYS / 2) - 1;
	init_button_nums(cub->control_box.buttons);
	get_button_txt(cub->control_box.buttons, cub);
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
	set_original_controls(&cub);
	raycasting(&cub);
	exit_cub(&cub, 0, "game finished successfully\n");
}
