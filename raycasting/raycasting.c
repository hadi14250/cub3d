/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:10:35 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/11 21:35:24 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



typedef struct s_loc_3d_wall_vars
{
	int		return_tex_val;
	int		dis_from_top;
	int		tex_offset_y;
	int		tex_offset_x;
}		t_wall_cords;

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

void	render_gun(t_cub *cub)
{
	int	size;

	size = 256;
	cub->sniper = mlx_xpm_file_to_image(cub->mlx, "./sniper.xpm", &size, &size);
	if (!cub->sniper)
		exit_cub(cub, 1, "gun not found\n");
	mlx_put_image_to_window(cub->mlx, cub->win, cub->sniper,
	WINDOW_WIDTH / 2, WINDOW_HEIGHT);
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
	t_wall_cords	cords;

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
		rays[x].correct_dist = rays[x].hit_distance * cos(rays[x].ray_angle - player->rotationangle);
		cub->proj_wall_h = (TILE_SIZE / rays[x].correct_dist) * player->dist_proj_plane;
		cub->wall_strip_height = (int)cub->proj_wall_h;
		cub->wall_top_pixel = (WINDOW_HEIGHT / 2) - (cub->wall_strip_height / 2);
		if (cub->wall_top_pixel < 0)
			cub->wall_top_pixel = 0;
		cub->wall_bottom_pixel = ((WINDOW_HEIGHT / 2) + (cub->wall_strip_height / 2));
		if (cub->wall_bottom_pixel > WINDOW_HEIGHT)
			cub->wall_bottom_pixel = WINDOW_HEIGHT;
		draw_3d_ceiling(cub, cub->wall_top_pixel, x);
		draw_3d_wall(cub, x, rays);
		draw_3d_floor(cub, cub->wall_bottom_pixel, x);
	}
}

void	render_color_buffer(t_cub *cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		y = -1;
		while (++y < WINDOW_HEIGHT)
			my_mlx_pixel_put(&cub->img, x, y,
				cub->color_buffer[(WINDOW_WIDTH * y) + x]);
	}
}

void	draw_background(t_img *img, t_cub *cub)
{
	t_rect	rect_up;
	t_rect	rect_down;

	rect_up = init_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2);
	rect_down = init_rect(0, (WINDOW_HEIGHT / 2) - 1,
			WINDOW_WIDTH, WINDOW_HEIGHT / 2);
	draw_rectangle(img, rect_up, cub->ceiling);
	draw_rectangle(img, rect_down, cub->floor);
}

void	init_player_pos(t_player *player)
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;

	y = -1;
	while (++y < player->map3d.height)
	{
		x = -1;
		while (++x < player->map3d.width)
		{
			if (player->map3d.map[y][x] == 'N'
				|| player->map3d.map[y][x] == 'W'
				|| player->map3d.map[y][x] == 'S'
				|| player->map3d.map[y][x] == 'E')
			{
				new_x = x;
				new_y = y;
				player->map3d.map[y][x] = '0';
			}
		}
	}
	printf("new_x: %d, new_y: %d\n", new_x, new_y);
	init_point(&player->pos, ((new_x * TILE_SIZE) + TILE_SIZE / 2),
	((new_y * TILE_SIZE) + TILE_SIZE / 2));
}

void	init_player(t_player *player, t_cub *cub)
{
	init_player_pos(player);
	// init_point(&player->pos, (MAP_NUM_COLS * TILE_SIZE) / 2,
	// 	(MAP_NUM_ROWS * TILE_SIZE) / 2);
	player->width = 3;
	player->height = 3;
	player->turndirection = 0;
	player->walkdirection = 0;
	player->rotationangle = cub->dir.actual_dir;
	player->walkspeed = 3;
	player->turnspeed = (1.5 * cub->fps) * (PI / 180);
	player->radius = 10;
}

void	init_map(t_cub *cub)
{
	cub->player.map3d.map = cub->map;
	cub->player.map3d.height = return_split_len(cub->map);
	cub->player.map3d.width = ft_strlen(
		cub->player.map3d.map[0]
	);
}

void	setup(t_cub *cub)
{
	cub->fps = 1;
	cub->scale_factor = MINIMAP_SCALE_FACTOR;
	cub->player.dist_proj_plane = DIST_PROJ_PLANE;
	init_map(cub);
	init_player(&cub->player, cub);
	//
	// for (int x = 0; x < TEX_WIDTH; x++)
	// {
	// 	for (int y = 0; y < TEXTURE_HEIGHT; y++)
	// 	{
	// 		cub->tex[TEXTURE_WIDTH * y + x] = (x % 8 && y % 8) ? 0x0000FF : 0x000000;
	// 	}
	// }
}

void	render_player(t_player *player, t_cub *cub)
{
	init_circle(&player->circle, player->pos.x * cub->scale_factor,
		player->pos.y * cub->scale_factor,
		player->radius * cub->scale_factor);
	draw_circle(&cub->img, player->circle, GREEN_COLOR);
}


void draw_cross(t_point cross, int size, int color, t_cub *cub)
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

// void	*aim = NULL;
void	draw_middle_circle(t_cub *cub, t_ray *rays)
{
	// int	size;
	t_circle	circle;
	t_point		cross;
	// size = 16;

	init_circle(&circle, rays[MID_RAY].wall_hit.x * cub->scale_factor,
		rays[MID_RAY].wall_hit.y * cub->scale_factor,
		10 * cub->scale_factor);
	draw_circle(&cub->img, circle, BLUE_COLOR);
	init_point(&cross, rays[MID_RAY].wall_hit.x * cub->scale_factor,
		rays[MID_RAY].wall_hit.y * cub->scale_factor);
	draw_cross(cross, 20 * cub->scale_factor, BLUE_COLOR, cub);
	// if (aim)
	// 	mlx_destroy_image(cub->mlx, aim);
	// aim = mlx_xpm_file_to_image(cub->mlx, "./game_textures/aim.xpm", &size, &size);
	// if (!aim)
	// 	exit_cub(cub, 1, "xpm file not found\n");
	// mlx_put_image_to_window(cub->mlx, cub->win, aim,
	// 	rays[MID_RAY].wall_hit.x * cub->scale_factor,
	// 	rays[MID_RAY].wall_hit.y * cub->scale_factor);
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
		init_point(&start, cub->player.pos.x * cub->scale_factor,
			cub->player.pos.y * cub->scale_factor);
		init_point(&end, rays[i].wall_hit.x * cub->scale_factor,
			rays[i].wall_hit.y * cub->scale_factor);

		init_circle(&circle, rays[i].wall_hit.x * cub->scale_factor,
			rays[i].wall_hit.y * cub->scale_factor,
			5 * cub->scale_factor);

		draw_bressen_line(&cub->img, start, end, BRIGHT_YELLOW);
		draw_circle(&cub->img, circle, RED_COLOR);
	}
	draw_middle_circle(cub, rays);
}

void	move_player(t_player *player, int flag)
{
	double	movestep;
	t_point	new_pos;

	player->rotationangle += player->turndirection * player->turnspeed;

	movestep = player->walkdirection * player->walkspeed;
	if (flag == 0)
	{
		new_pos.x = player->pos.x + (cos(player->rotationangle) * movestep);
		new_pos.y = player->pos.y + (sin(player->rotationangle) * movestep);
	}
	else
	{
		new_pos.x = player->pos.x + (cos(player->rotationangle - (M_PI_2)) * movestep);
		new_pos.y = player->pos.y + (sin(player->rotationangle - (M_PI_2)) * movestep);
	}
	if (!maphaswallat(new_pos.x, new_pos.y, player))
	{
		player->pos.x = new_pos.x;
		player->pos.y = new_pos.y;
	}
}

void	normalize_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

void	cast_horz_ray(double ray_angle, t_ray *ray, t_player *player)
{
	ray->foundHorzWallHit = false;
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
			ray->foundHorzWallHit = true;
			break ;
		}
		else
		{
			ray->next_h_touch.x += ray->h_step.x;
			ray->next_h_touch.y += ray->h_step.y;
		}
	}
}

void	cast_vert_ray(double ray_angle, t_ray *ray, t_player *player)
{
	ray->foundVertWallHit = false;
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
			ray->foundVertWallHit = true;
			break ;
		}
		else
		{
			ray->next_v_touch.x += ray->v_step.x;
			ray->next_v_touch.y += ray->v_step.y;
		}
	}
}

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
	if (ray->foundHorzWallHit)
		ray->horz_hit_distance = delta_points(player->pos.x,
				player->pos.y, ray->horz_wallhit.x, ray->horz_wallhit.y);
	else
		ray->horz_hit_distance = INT_MAX;
	if (ray->foundVertWallHit)
		ray->vert_hit_distance = delta_points(player->pos.x,
				player->pos.y, ray->vert_wallhit.x, ray->vert_wallhit.y);
	else
		ray->vert_hit_distance = INT_MAX;
	if (ray->vert_hit_distance < ray->horz_hit_distance)
		set_vert_data(ray);
	else
		set_horz_data(ray);
}

void	cast_ray(double ray_angle, t_ray *ray, int stripid, t_player *player)
{
	init_ray(ray_angle, ray, stripid);
	cast_horz_ray(ray_angle, ray, player);
	cast_vert_ray(ray_angle, ray, player);
	calculate_smallest_distance(ray, player);
}

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

void	update(t_cub *cub)
{
	// cub->img.img_ptr = free_img(cub->img.img_ptr, cub->mlx);
	// cub->img.img_ptr = cub_new_img(&cub->img, cub->mlx,
	// 		WINDOW_WIDTH, WINDOW_HEIGHT);
	// ft_bzero(cub->img.img_ptr, cub->img.height * cub->img.width);
	// if (!cub->img.img_ptr)
	// 	exit_cub(cub, 1, "Error\n, can't allocate image\n");
	cast_all_rays(cub->player.rays, &cub->player);
	move_player(&cub->player, cub->p_flag);
	generate_3d_wprojection(&cub->player, cub->player.rays, cub);
	render_color_buffer(cub);
}

// render all objects for the current frame
void	render(t_cub *cub)
{
	// generate_3d_wprojection(&cub->player, cub->player.rays, cub);
	// render_color_buffer(cub);
	render_map(cub);
	render_rays(cub, cub->player.rays);
	render_player(&cub->player, cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img_ptr, 0, 0);
}

void	raycasting(t_cub *cub)
{
	setup(cub);
	update(cub);
	render(cub);
	// render_gun(cub);
	hook_keys(cub);
	mlx_loop(cub->mlx);
}
