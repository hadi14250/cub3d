/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:10:35 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/27 10:32:01 by hakaddou         ###   ########.fr       */
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

void	put_big_rifle(t_cub *cub)
{
	int	size;

	size = 540;
	if (cub->gun)
		mlx_destroy_image(cub->mlx, cub->gun);
	cub->gun = mlx_xpm_file_to_image(cub->mlx,
		"./game_textures/big_rifle.xpm", &size, &size);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->gun,
		(WINDOW_WIDTH) - (size * 1.5),
		WINDOW_HEIGHT - size);
}

void	put_machine_gun_aimed(t_cub *cub)
{
	int	width;
	int	height;

	width = 711;
	height = 351;
	if (cub->gun)
		mlx_destroy_image(cub->mlx, cub->gun);
	cub->gun = mlx_xpm_file_to_image(cub->mlx,
		"./game_textures/machine_gun_aimed.xpm", &width, &height);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->gun,
		(WINDOW_WIDTH / 2) - (width / 2),
		WINDOW_HEIGHT - (height - 20));
}

void	put_aim(t_cub *cub)
{
	int	width;
	int	height;

	width = 711;
	height = 351;
	if (cub->gun)
		mlx_destroy_image(cub->mlx, cub->gun);
	cub->gun = mlx_xpm_file_to_image(cub->mlx,
		"./game_textures/aiming.xpm", &width, &height);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->gun,
		(WINDOW_WIDTH / 2) - (width / 2),
		WINDOW_HEIGHT - (height - 20));
}

void	put_machine_gun(t_cub *cub)
{
	int	size;

	size = 540;
	if (cub->gun)
		mlx_destroy_image(cub->mlx, cub->gun);
	cub->gun = mlx_xpm_file_to_image(cub->mlx,
		"./game_textures/machine_gun.xpm", &size, &size);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->gun,
		(WINDOW_WIDTH / 2) - (size / 2),
		WINDOW_HEIGHT - size);
}

void	render(t_cub *cub)
{
	if (cub->keys.c)
	{
		print_control_box(cub);
		cub->player.map3d.y_scale_factor /= 2;
		cub->player.map3d.x_scale_factor /= 2;
	}
	if(cub->keys.c && cub->keys.f)
	{
		cub->player.map3d.y_scale_factor /= 3;
		cub->player.map3d.x_scale_factor /= 3;
	}
	if (cub->keys.q == false)
	{
		render_map(cub);
		render_rays(cub, cub->player.rays);
		render_player(&cub->player, cub);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img_ptr, 0, 0);
	if (cub->keys.c)
		print_all_strings(cub->control_box.buttons, cub);
	if (!cub->keys.f && !cub->keys.c && 
		!cub->button_controls.remove_machine_gun)
		put_machine_gun(cub);
}

void	raycasting(t_cub *cub)
{
	setup(cub);
	update(cub);
	render(cub);
	hook_keys(cub);
	mlx_loop(cub->mlx);
}
