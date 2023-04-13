/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checks_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:19:22 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 06:19:32 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	animate_aim(t_cub *cub)
{
	cub->player.dist_proj_plane = (((WINDOW_WIDTH * (cub->aim_factor))
				/ tan(cub->player.fov / 2)));
	rerender(cub);
	cub->aim_factor += AIM_ZOOM_INCREMENT;
	cub->fps -= 1;
}

void	check_for_exit(int key, t_cub *cub)
{
	if (key == ESC)
	{
		cub->img.img_ptr = free_img(cub->img.img_ptr, cub->mlx);
		cub->win = free_window(cub->mlx, cub->win);
		exit_cub(cub, 0, "\nGame finished successfully ✅\n");
	}
}

void	check_map_scaling(int key, t_cub *cub)
{
	if (key == PLUS_KEY)
	{
		if (cub->scale_factor < 1 - MINIMAP_SCALE_FACTOR)
		{
			cub->scale_factor += MINIMAP_SCALE_FACTOR;
			rerender(cub);
		}
		return ;
	}
	if (key == MINUS_KEY)
	{
		if (cub->scale_factor > MINIMAP_SCALE_FACTOR)
			cub->scale_factor -= MINIMAP_SCALE_FACTOR;
		rerender(cub);
	}
}

void	check_aiming(int key, t_cub *cub)
{
	if (key == SHIFT || key == SHIFT - 1)
	{
		cub->keys.aim = true;
		cub->fps = AIM_ZOOM_FPS;
		cub->aim_factor = 0.5;
	}
}
