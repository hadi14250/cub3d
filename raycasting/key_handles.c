/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:08 by hakaddou          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/07 16:11:25 by bsaeed           ###   ########.fr       */
=======
/*   Updated: 2023/04/09 01:49:45 by hakaddou         ###   ########.fr       */
>>>>>>> origin/hadi
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// if the key is clicked, then we upudate depeends on what was
// clicked and set the rest to zero

<<<<<<< HEAD
=======
void    mouse_funcs(t_cub *cub, int flag)
{
	if (flag == 0)
	{
		cub->keys.left = true;
		if (cub->keys.right == true)
			cub->keys.right = false;
	}
	if (flag == 1)
	{
		cub->keys.right = true;
		if (cub->keys.left == true)
			cub->keys.left = false;
	}
	if (flag == 2)
	{
		cub->keys.right = false;
		cub->keys.left = false;
	}
}

int mouse_events(int x, int y, t_cub *cub)
{
	static int  prev_x;
	static int flag = 0;

	(void)y;
	if (flag == 0)
		flag = 1;
	else if (flag == 1)
		flag = 0;
	if (x < prev_x)
		mouse_funcs(cub, 0);
	else if ((x > prev_x))
		mouse_funcs(cub, 1);
	if (flag == 0 || x == prev_x)
		mouse_funcs(cub, 2);
	prev_x = x;
	return 0;
}
>>>>>>> origin/hadi

int	keys_handler(int key, t_cub *cub)
{
	if (key == ESC)
	{
		cub->img.img_ptr = free_img(cub->img.img_ptr, cub->mlx);
		cub->win = free_window(cub->mlx, cub->win);
		exit (0);
	}
<<<<<<< HEAD
	if (key == W_KEY)
		cub->keys.up = true;
	if (key == S_KEY)
=======
	if (key == A_KEY)
	{
		cub->p_flag = 1;
		cub->keys.up = true;
	}
	if (key == D_KEY)
	{
		cub->p_flag = 1;
		cub->keys.down = true;
	}
	if (key == W_KEY)
	{
		cub->keys.up = true;
		cub->p_flag = 0;
	}
	if (key == S_KEY)
	{
>>>>>>> origin/hadi
		cub->keys.down = true;
		cub->p_flag = 0;
	}
	if (key == LEFT_AROW)
		cub->keys.left = true;
	if (key == RIGHT_AROW)
		cub->keys.right = true;
	return (0);
}

// int	mouse_handler(int x, int y, t_cub *cub)
// {
// 	if (x < WINDOW_WIDTH / 2 && (y > 0 && y < WINDOW_HEIGHT))
// 		printf("moved to the right\n");
// 	else
// 		printf("moved left\n");
// 	// mlx_mouse_move(cub->win, WINDOW_HEIGHT/2, WINDOW_WIDTH/2);
// 	//ft_start(g);
// 	return (0);
// }

int	keys_released(int key, t_cub *cub)
{

<<<<<<< HEAD
	if (key == W_KEY)
		cub->keys.up = false;
=======
	if (key == A_KEY)
		cub->keys.up = false;
	if (key == D_KEY)
		cub->keys.down = false;
	if (key == W_KEY)
		cub->keys.up = false;
>>>>>>> origin/hadi
	if (key == S_KEY)
		cub->keys.down = false;
	if (key == LEFT_AROW)
		cub->keys.left = false;
	if (key == RIGHT_AROW)
		cub->keys.right = false;
	if (key == A_KEY)
		cub->keys.left = false;
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
	if (cub->keys.up == false)
		cub->player.walkdirection = 0;
	if (cub->keys.down == false)
		cub->player.walkdirection = 0;
	if (cub->keys.right == false)
		cub->player.turndirection = 0;
	if (cub->keys.left == false)
		cub->player.turndirection = 0;

	if (cub->keys.up == true)
		cub->player.walkdirection = 1;
	if (cub->keys.down == true)
		cub->player.walkdirection = -1;
	if (cub->keys.right == true)
		cub->player.turndirection = 1;
	if (cub->keys.left == true)
		cub->player.turndirection = -1;
	if (ft_memchr(&cub->keys, 1, sizeof(t_keys)))
	{
		update(cub);
		render(cub);
	}
	return (0);
}

void	hook_keys(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0, exit_app, cub);
	mlx_hook(cub->win, 2, 0, keys_handler, cub);
	mlx_hook(cub->win, 3, 0, keys_released, cub);
<<<<<<< HEAD
	// mlx_hook(cub->win, 6, 0, mouse_handler, cub);
=======
	mlx_hook(cub->win, 6, 1L<<6, mouse_events, cub);
>>>>>>> origin/hadi
	mlx_loop_hook(cub->mlx, render_loop, cub);
}
