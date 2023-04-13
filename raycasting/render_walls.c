/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:20:02 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 05:20:22 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	return_tex_val(t_cub *cub, int x, t_wall_cords cords, t_ray *rays)
{
	cords.return_tex_val = 0;
	if (rays[x].is_ray_facing_right && rays[x].washitvertical)
		cords.return_tex_val = cub->img2[0].address[
			(cub->img2[0].width * cords.tex_offset_y)
			+ cords.tex_offset_x];
	else if (rays[x].is_ray_facing_up && !rays[x].washitvertical)
		cords.return_tex_val = cub->img2[2].address[
			(cub->img2[2].width * cords.tex_offset_y)
			+ cords.tex_offset_x];
	else if (rays[x].is_ray_facing_left && rays[x].washitvertical)
		cords.return_tex_val = cub->img2[1].address[
			(cub->img2[1].width * cords.tex_offset_y)
			+ cords.tex_offset_x];
	else if (rays[x].is_ray_facing_down
		&& !rays[x].washitvertical)
		cords.return_tex_val = cub->img2[3].address[
			(cub->img2[3].width * cords.tex_offset_y)
			+ cords.tex_offset_x];
	return (cords.return_tex_val);
}

void	draw_3d_ceiling(t_cub *cub, int wall_top_pixel, int x)
{
	int	y;

	y = -1;
	while (++y < wall_top_pixel)
		cub->color_buffer[(WINDOW_WIDTH * y) + x] = cub->ceiling;
}

void	draw_3d_floor(t_cub *cub, int wall_bottom_pixel, int x)
{
	int	y;

	y = wall_bottom_pixel;
	while (y < WINDOW_HEIGHT)
	{
		cub->color_buffer[(WINDOW_WIDTH * y) + x] = cub->floor;
		y++;
	}
}

void	draw_3d_wall(t_cub *cub, int x, t_ray *rays)
{
	int					y;
	t_wall_cords		cords;

	cub->t_size = TILE_SIZE;
	bzero(&cords, sizeof(t_wall_cords));
	y = cub->wall_top_pixel;
	if (rays[x].washitvertical)
		cords.tex_offset_x = (int)rays[x].wall_hit.y % cub->t_size;
	else
		cords.tex_offset_x = (int)rays[x].wall_hit.x % cub->t_size;
	while (y < cub->wall_bottom_pixel)
	{
		cords.dis_from_top = y + ((cub->wall_strip_height / 2)
				- (WINDOW_HEIGHT / 2));
		cords.tex_offset_y = cords.dis_from_top
			* ((float)cub->img2[0].height / cub->wall_strip_height);
		cords.return_tex_val = return_tex_val(cub, x, cords, rays);
		cub->color_buffer[(WINDOW_WIDTH * y) + x] = cords.return_tex_val;
		y++;
	}
}

void	generate_3d_wprojection(t_player *player, t_ray *rays, t_cub *cub)
{
	int	x;

	x = -1;
	while (++x < NUM_RAYS)
	{
		rays[x].correct_dist = rays[x].hit_distance * cos(rays[x].ray_angle
				- player->rotationangle);
		cub->proj_wall_h = (TILE_SIZE / rays[x].correct_dist)
			* player->dist_proj_plane;
		cub->wall_strip_height = (int)cub->proj_wall_h;
		cub->wall_top_pixel = (WINDOW_HEIGHT / 2)
			- (cub->wall_strip_height / 2);
		if (cub->wall_top_pixel < 0)
			cub->wall_top_pixel = 0;
		cub->wall_bottom_pixel = ((WINDOW_HEIGHT / 2)
				+ (cub->wall_strip_height / 2));
		if (cub->wall_bottom_pixel > WINDOW_HEIGHT)
			cub->wall_bottom_pixel = WINDOW_HEIGHT;
		draw_3d_ceiling(cub, cub->wall_top_pixel, x);
		draw_3d_wall(cub, x, rays);
		draw_3d_floor(cub, cub->wall_bottom_pixel, x);
	}
}
