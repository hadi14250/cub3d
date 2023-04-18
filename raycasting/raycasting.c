/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:10:35 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 07:18:38 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// we start from the left most ray by substracting
// the player rotation angle from FOV
void	cast_all_rays(t_ray *rays, t_player *player)
{
	double	ray_angle;
	int		i;

	i = -1;
	while (++i < NUM_RAYS)
	{
		ray_angle = player->rotationangle
			+ atan((i - NUM_RAYS / 2) / player->dist_proj_plane);
		cast_ray(ray_angle, &rays[i], i, player);
	}
}

void	setup(t_cub *cub)
{
	cub->fps = 1;
	init_map(cub);
	cub->scale_factor = MINIMAP_SCALE_FACTOR;
	set_minimap_scalefactor(cub);
	init_player(&cub->player, cub);
}

void	update(t_cub *cub)
{
	set_minimap_scalefactor(cub);
	cast_all_rays(cub->player.rays, &cub->player);
	move_player(&cub->player, cub->p_flag);
	generate_3d_wprojection(&cub->player, cub->player.rays, cub);
	render_color_buffer(cub);
}

void	render(t_cub *cub)
{
	if (cub->keys.q == false)
	{
		render_map(cub);
		render_rays(cub, cub->player.rays);
		render_player(&cub->player, cub);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img_ptr, 0, 0);
}

void	raycasting(t_cub *cub)
{
	setup(cub);
	update(cub);
	render(cub);
	hook_keys(cub);
	mlx_loop(cub->mlx);
}
