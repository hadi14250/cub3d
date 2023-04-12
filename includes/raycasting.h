/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:16:47 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/12 19:37:54 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_ray
{
	t_point	horz_wallhit;
	t_point	vert_wallhit;
	t_point	h_intercept;
	t_point	v_intercept;
	t_point	h_step;
	t_point	v_step;
	t_point	next_h_touch;
	t_point	next_v_touch;
	t_point	to_check;
	t_point	wall_hit;
	double	ray_angle;
	double	horz_hit_distance;
	double	vert_hit_distance;
	double	hit_distance;
	bool	washitvertical;
	bool	is_ray_facing_up;
	bool	is_ray_facing_down;
	bool	is_ray_facing_right;
	bool	is_ray_facing_left;
	bool	foundHorzWallHit;
	bool	foundVertWallHit;
	int		wall_hit_content;
	int		horz_wall_content;
	int		vert_wall_content;
	int		stripid;
	double	correct_dist;
}			t_ray;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	double	x_scale_factor;
	double	y_scale_factor;
}			t_map;

typedef struct s_player
{
	t_point		pos;
	t_circle	circle;
	t_rect		rect;
	t_point		l_start_pos;
	t_point		l_end_pos;
	int			radius;
	float		width;
	float		height;
	int			turndirection; // -1 for left and 1 or right
	int			walkdirection; // -1 if walking backwards and +1 if walking front
	float		rotationangle;
	float		walkspeed;
	float		turnspeed;
	t_ray		rays[NUM_RAYS];
	double		dist_proj_plane;
	t_map		map3d;
}			t_player;

#endif