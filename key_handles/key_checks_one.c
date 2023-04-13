/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checks_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:17:45 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 07:10:47 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_left_right_move(int key, t_cub *cub)
{
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
}

void	check_player_movement(int key, t_cub *cub)
{
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
	check_left_right_move(key, cub);
}

void	check_direction(int key, t_cub *cub)
{
	if (key == LEFT_AROW)
		cub->keys.left = true;
	if (key == RIGHT_AROW)
		cub->keys.right = true;
}

void	check_full_screen(int key, t_cub *cub)
{
	if (!cub->keys.q && (key == F_KEY))
	{
		if (cub->scale_factor == MINIMAP_SCALE_FACTOR)
			cub->scale_factor = 1;
		else
			cub->scale_factor = MINIMAP_SCALE_FACTOR;
		rerender(cub);
	}
}

void	check_quitting_mini_map(int key, t_cub *cub)
{
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
}
