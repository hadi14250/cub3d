/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:24:50 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 05:25:06 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_player(t_player *player, t_cub *cub)
{
	init_circle(&player->circle, player->pos.x * player->map3d.x_scale_factor,
		player->pos.y * player->map3d.y_scale_factor,
		player->radius * player->map3d.small_factor);
	draw_circle(&cub->img, player->circle, GREEN_COLOR);
}

void	draw_cross(t_point cross, int size, int color, t_cub *cub)
{
	t_point	start;
	t_point	end;

	init_point(&start, (cross.x - size), (cross.y - size));
	init_point(&end, (cross.x + size), (cross.y + size));
	draw_bressen_line(&cub->img, start, end, color);
	init_point(&start, (cross.x - size), (cross.y + size));
	init_point(&end, (cross.x + size), (cross.y - size));
	draw_bressen_line(&cub->img, start, end, color);
}

double	return_smallest(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	draw_middle_circle(t_cub *cub, t_ray *rays)
{
	t_circle	circle;
	t_point		cross;
	int			mid;

	mid = cub->player.mid_ray;
	if (cub->player.map3d.x_scale_factor < cub->player.map3d.y_scale_factor)
		cub->player.map3d.small_factor = cub->player.map3d.x_scale_factor;
	else
		cub->player.map3d.small_factor = cub->player.map3d.y_scale_factor;
	init_circle(&circle, rays[mid].wall_hit.x
		* cub->player.map3d.x_scale_factor,
		rays[mid].wall_hit.y * cub->player.map3d.y_scale_factor,
		10 * cub->player.map3d.small_factor);
	draw_circle(&cub->img, circle, BLUE_COLOR);
	init_point(&cross, rays[mid].wall_hit.x * cub->player.map3d.x_scale_factor,
		rays[mid].wall_hit.y * cub->player.map3d.y_scale_factor);
	draw_cross(cross, 20 * cub->player.map3d.small_factor, BLUE_COLOR, cub);
}

void	render_rays(t_cub *cub, t_ray *rays)
{
	int			i;
	t_point		start;
	t_point		end;
	t_circle	circle;

	i = -1;
	while (++i < NUM_RAYS)
	{
		init_point(&start, cub->player.pos.x * cub->player.map3d.x_scale_factor,
			cub->player.pos.y * cub->player.map3d.y_scale_factor);
		init_point(&end, rays[i].wall_hit.x * cub->player.map3d.x_scale_factor,
			rays[i].wall_hit.y * cub->player.map3d.y_scale_factor);
		init_circle(&circle, rays[i].wall_hit.x
			* cub->player.map3d.x_scale_factor,
			rays[i].wall_hit.y * cub->player.map3d.y_scale_factor,
			10 * cub->player.map3d.small_factor);
		draw_bressen_line(&cub->img, start, end, BRIGHT_YELLOW);
		draw_circle(&cub->img, circle, RED_COLOR);
	}
	draw_middle_circle(cub, rays);
}
