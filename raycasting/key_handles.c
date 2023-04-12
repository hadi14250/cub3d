/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:08 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/12 18:35:10 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// if the key is clicked, then we upudate depeends on what was
// clicked and set the rest to zero

void	rerender(t_cub *cub)
{
	update(cub);
	render(cub);
	// render_gun(cub);
}

void    mouse_funcs(t_cub *cub, int flag)
{
	if (flag == 0)
		cub->keys.m_left = true;
	if (flag == 1)
		cub->keys.m_right = true;
	if (flag == 2)
	{
		cub->keys.m_left = false;
		cub->keys.m_right = false;
	}
}

int mouse_events(int x, int y, t_cub *cub)
{
	static int	prev_x;

	(void)y;
	if (x < prev_x)
		mouse_funcs(cub, 0);
	else if ((x > prev_x))
		mouse_funcs(cub, 1);
	if (x > WINDOW_WIDTH || x < 0)
		mlx_mouse_move(cub->win, (WINDOW_WIDTH/2), (WINDOW_HEIGHT/2));
	if (x == prev_x)
		mouse_funcs(cub, 2);
	prev_x = x;
	return (0);
}

void	animate_aim(t_cub *cub)
{
	cub->player.dist_proj_plane = 
	(((WINDOW_WIDTH * (cub->aim_factor)) / tan(FOV_ANGLE / 2)));
	rerender(cub);
	cub->aim_factor += AIM_ZOOM_INCREMENT;
	cub->fps -= 1;
}

int	keys_handler(int key, t_cub *cub)
{
	if (key == ESC)
	{
		cub->img.img_ptr = free_img(cub->img.img_ptr, cub->mlx);
		cub->win = free_window(cub->mlx, cub->win);
		exit (0);
	}
	if (key == A_KEY)
	{
		cub->p_flag = 1;
		if (cub->keys.down)
			cub->keys.down = false;
		cub->keys.up = true;
	}
	if (key == D_KEY)
	{
		cub->p_flag = 1;
		if (cub->keys.up == true)
			cub->keys.up = false;
		cub->keys.down = true;
	}
	if (key == W_KEY)
	{
		cub->p_flag = 0;
		if (cub->keys.down == true)
			cub->keys.down = false;
		cub->keys.up = true;
	}
	if (key == S_KEY)
	{
		cub->p_flag = 0;
		if (cub->keys.up == true)
			cub->keys.up = false;
		cub->keys.down = true;
	}
	if (key == LEFT_AROW)
		cub->keys.left = true;
	if (key == RIGHT_AROW)
		cub->keys.right = true;
	if (!cub->keys.q && (key == F_KEY))
	{
		if (cub->scale_factor == MINIMAP_SCALE_FACTOR)
			cub->scale_factor = 1;
		else
			cub->scale_factor = MINIMAP_SCALE_FACTOR;
		rerender(cub);
	}
	if (key == Q_KEY)
	{
		if (cub->keys.q == false)
		{
			cub->keys.q = true;
			rerender(cub);
		}
		else
		{
			if (cub->keys.q == true)
			{
				cub->keys.q = false;
				rerender(cub);
			}
		}
	}
	if (key == PLUS_KEY)
	{
		if (cub->scale_factor < 0.99)
		{
			cub->scale_factor += MINIMAP_SCALE_FACTOR;
			printf("Scale factor is %f\n", cub->scale_factor);
		}
		rerender(cub);
		return (0);
	}
	if (key == MINUS_KEY)
	{
		if (cub->scale_factor > MINIMAP_SCALE_FACTOR)
			cub->scale_factor -= MINIMAP_SCALE_FACTOR;
		rerender(cub);
	}
	if (key == SHIFT || key == SHIFT - 1)
	{
		cub->keys.aim = true;
		cub->fps = AIM_ZOOM_FPS;
		cub->aim_factor = 0.5;
	}
	return (0);
}

int	keys_released(int key, t_cub *cub)
{
	if (key == A_KEY)
		cub->keys.up = false;
	if (key == D_KEY)
		cub->keys.down = false;
	if (key == W_KEY)
		cub->keys.up = false;
	if (key == S_KEY)
		cub->keys.down = false;
	if (key == LEFT_AROW)
		cub->keys.left = false;
	if (key == RIGHT_AROW)
		cub->keys.right = false;
	if (key == A_KEY)
		cub->keys.left = false;
	if (key == SHIFT || key == SHIFT - 1)
	{
		cub->player.dist_proj_plane = 
			((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2));
		cub->keys.aim = false;
		rerender(cub);
	}
		
	return (0);
}

int	exit_app(t_cub *cub)
{
	cub->img.img_ptr = free_img(cub->img.img_ptr, cub->mlx);
	cub->win = free_window(cub->mlx, cub->win);
	free(cub->color_buffer);
	free(cub->tex);
	exit(0);
	return (0);
}

int	render_loop(t_cub *cub)
{
	int	x, y;

	mlx_mouse_get_pos(cub->win, &x, &y);
	mouse_events(x, y, cub);
	if (cub->keys.up == false)
		cub->player.walkdirection = 0;
	if (cub->keys.down == false)
		cub->player.walkdirection = 0;
	if (cub->keys.right == false && cub->keys.m_right == false)
		cub->player.turndirection = 0;
	if (cub->keys.left == false && cub->keys.m_left == false)
		cub->player.turndirection = 0;
	if (cub->keys.up == true)
		cub->player.walkdirection = 1;
	if (cub->keys.down == true)
		cub->player.walkdirection = -1;
	if (cub->keys.right == true || cub->keys.m_right == true)
		cub->player.turndirection = 1;
	if (cub->keys.left == true || cub->keys.m_left == true)
		cub->player.turndirection = -1;
	if (cub->keys.aim == true)
	{
		if (cub->fps >= 0)
			animate_aim(cub);
		else
			cub->keys.aim = false;
	}

	if (ft_memchr(&cub->keys, 1, sizeof(t_keys)))
		rerender(cub);
	return (0);
}

void	hook_keys(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0, exit_app, cub);
	mlx_hook(cub->win, 2, 0, keys_handler, cub);
	mlx_hook(cub->win, 3, 0, keys_released, cub);
	mlx_loop_hook(cub->mlx, render_loop, cub);
}
