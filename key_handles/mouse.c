/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:16:15 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 06:16:27 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mouse_funcs(t_cub *cub, int flag)
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

int	mouse_events(int x, int y, t_cub *cub)
{
	static int	prev_x;

	(void)y;
	if (x < prev_x)
		mouse_funcs(cub, 0);
	else if ((x > prev_x))
		mouse_funcs(cub, 1);
	if (x > WINDOW_WIDTH || x < 0)
		mlx_mouse_move(cub->win, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2));
	if (x == prev_x)
		mouse_funcs(cub, 2);
	prev_x = x;
	return (0);
}

void	start_mouse(t_cub *cub)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cub->win, &x, &y);
	mouse_events(x, y, cub);
}
