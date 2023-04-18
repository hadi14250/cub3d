/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:26:23 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 05:26:36 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_h_ray_point(double ray_angle, t_ray *ray, t_player *player)
{
	ray->found_h_hit = false;
	init_point(&ray->horz_wallhit, 0, 0);
	ray->horz_wall_content = 0;
	ray->h_intercept.y = floor(player->pos.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_down)
		ray->h_intercept.y += TILE_SIZE;
	ray->h_intercept.x = player->pos.x + (
			(ray->h_intercept.y - player->pos.y) / tan(ray_angle));
	ray->h_step.y = TILE_SIZE;
	if (ray->is_ray_facing_up)
		ray->h_step.y *= -1;
	ray->h_step.x = TILE_SIZE / tan(ray_angle);
	if (ray->is_ray_facing_left && ray->h_step.x > 0)
		ray->h_step.x *= -1;
	if (ray->is_ray_facing_right && ray->h_step.x < 0)
		ray->h_step.x *= -1;
	ray->next_h_touch.x = ray->h_intercept.x;
	ray->next_h_touch.y = ray->h_intercept.y;
}

void	cast_horz_ray(double ray_angle, t_ray *ray, t_player *player)
{
	set_h_ray_point(ray_angle, ray, player);
	while (is_inside_map(ray->next_h_touch.x, ray->next_h_touch.y, player))
	{
		if (ray->is_ray_facing_up)
			init_point(&ray->to_check, ray->next_h_touch.x,
				ray->next_h_touch.y - 1);
		else
			init_point(&ray->to_check, ray->next_h_touch.x,
				ray->next_h_touch.y);
		if (maphaswallat(ray->to_check.x, ray->to_check.y, player))
		{
			ray->horz_wallhit.x = ray->next_h_touch.x;
			ray->horz_wallhit.y = ray->next_h_touch.y;
			ray->horz_wall_content = get_map_at(
					floor(ray->to_check.y / TILE_SIZE),
					floor(ray->to_check.x / TILE_SIZE), player);
			ray->found_h_hit = true;
			break ;
		}
		else
		{
			ray->next_h_touch.x += ray->h_step.x;
			ray->next_h_touch.y += ray->h_step.y;
		}
	}
}

void	set_v_ray_point(double ray_angle, t_ray *ray, t_player *player)
{
	ray->found_v_hit = false;
	init_point(&ray->vert_wallhit, 0, 0);
	ray->vert_wall_content = 0;
	ray->v_intercept.x = floor(player->pos.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		ray->v_intercept.x += TILE_SIZE;
	ray->v_intercept.y = player->pos.y + (
			(ray->v_intercept.x - player->pos.x) * tan(ray_angle));
	ray->v_step.x = TILE_SIZE;
	if (ray->is_ray_facing_left)
		ray->v_step.x *= -1;
	ray->v_step.y = TILE_SIZE * tan(ray_angle);
	if (ray->is_ray_facing_up && ray->v_step.y > 0)
		ray->v_step.y *= -1;
	if (ray->is_ray_facing_down && ray->v_step.y < 0)
		ray->v_step.y *= -1;
	ray->next_v_touch.x = ray->v_intercept.x;
	ray->next_v_touch.y = ray->v_intercept.y;
}

void	cast_vert_ray(double ray_angle, t_ray *ray, t_player *player)
{
	set_v_ray_point(ray_angle, ray, player);
	while (is_inside_map(ray->next_v_touch.x, ray->next_v_touch.y, player))
	{
		if (ray->is_ray_facing_left)
			init_point(&ray->to_check, ray->next_v_touch.x - 1,
				ray->next_v_touch.y);
		else
			init_point(&ray->to_check, ray->next_v_touch.x,
				ray->next_v_touch.y);
		if (maphaswallat(ray->to_check.x, ray->to_check.y, player))
		{
			ray->vert_wallhit.x = ray->next_v_touch.x;
			ray->vert_wallhit.y = ray->next_v_touch.y;
			ray->vert_wall_content = get_map_at(
					floor(ray->to_check.y / TILE_SIZE),
					floor(ray->to_check.x / TILE_SIZE), player);
			ray->found_v_hit = true;
			break ;
		}
		else
		{
			ray->next_v_touch.x += ray->v_step.x;
			ray->next_v_touch.y += ray->v_step.y;
		}
	}
}

void	cast_ray(double ray_angle, t_ray *ray, int stripid, t_player *player)
{
	init_ray(ray_angle, ray, stripid);
	cast_horz_ray(ray_angle, ray, player);
	cast_vert_ray(ray_angle, ray, player);
	calculate_smallest_distance(ray, player);
}
