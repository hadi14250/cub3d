/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:27:23 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 05:27:39 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	normalize_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
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
		new_pos.x = player->pos.x + (cos(player->rotationangle
					- (M_PI_2)) * movestep);
		new_pos.y = player->pos.y + (sin(player->rotationangle
					- (M_PI_2)) * movestep);
	}
	if (!maphaswallat(new_pos.x, new_pos.y, player))
	{
		player->pos.x = new_pos.x;
		player->pos.y = new_pos.y;
	}
}
