/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:05:29 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 05:17:43 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray(double ray_angle, t_ray *ray, int stripid)
{
	ray->ray_angle = ray_angle;
	normalize_angle(&ray->ray_angle);
	ray->is_ray_facing_down = (ray->ray_angle > 0 && ray->ray_angle < PI);
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = (ray->ray_angle > (1.5 * PI)
			|| ray->ray_angle < (PI / 2));
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
	ray->stripid = stripid;
}

// returns the difference between 2 points using the pythagoras theorem
double	delta_points(double x1, double y1, double x2, double y2)
{
	return (
		sqrt(
			((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))
		)
	);
}

void	set_horz_data(t_ray *ray)
{
	ray->hit_distance = ray->horz_hit_distance;
	ray->wall_hit.x = ray->horz_wallhit.x;
	ray->wall_hit.y = ray->horz_wallhit.y;
	ray->wall_hit_content = ray->horz_wall_content;
	ray->washitvertical = false;
}

void	set_vert_data(t_ray *ray)
{
	ray->hit_distance = ray->vert_hit_distance;
	ray->wall_hit.x = ray->vert_wallhit.x;
	ray->wall_hit.y = ray->vert_wallhit.y;
	ray->wall_hit_content = ray->vert_wall_content;
	ray->washitvertical = true;
}

void	calculate_smallest_distance(t_ray *ray, t_player *player)
{
	if (ray->found_h_hit)
		ray->horz_hit_distance = delta_points(player->pos.x,
				player->pos.y, ray->horz_wallhit.x, ray->horz_wallhit.y);
	else
		ray->horz_hit_distance = INT_MAX;
	if (ray->found_v_hit)
		ray->vert_hit_distance = delta_points(player->pos.x,
				player->pos.y, ray->vert_wallhit.x, ray->vert_wallhit.y);
	else
		ray->vert_hit_distance = INT_MAX;
	if (ray->vert_hit_distance < ray->horz_hit_distance)
		set_vert_data(ray);
	else
		set_horz_data(ray);
}
