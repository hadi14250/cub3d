/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:18:09 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 07:04:48 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	maphaswallat(double x, double y, t_player *player)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = floor(x / TILE_SIZE);
	map_index_y = floor(y / TILE_SIZE);
	if (x < 0 || x > player->map3d.width * TILE_SIZE
		|| y < 0 || y > player->map3d.height * TILE_SIZE)
		return (true);
	if (player->map3d.map[map_index_y][map_index_x] == '0')
		return (false);
	return (true);
}

int	get_map_at(int i, int j, t_player *player)
{
	return (player->map3d.map[i][j]);
}

bool	is_inside_map(double x, double y, t_player *player)
{
	return (x >= 0 && x <= player->map3d.width * TILE_SIZE
		&& y >= 0 && y <= player->map3d.height * TILE_SIZE);
}

int	return_color(t_cub *cub, int tilecolor)
{
	if (cub->keys.t == true)
		return (0xFFFFFFFF);
	else
		return (tilecolor);
}

void	render_map(t_cub *cub)
{
	int		i;
	int		j;
	t_point	tile;
	int		tilecolor;
	t_rect	rect;

	i = -1;
	j = -1;
	while (++i < cub->player.map3d.height)
	{
		j = -1;
		while (++j < cub->player.map3d.width)
		{
			init_point(&tile, j * TILE_SIZE, i * TILE_SIZE);
			if (cub->player.map3d.map[i][j] == '1')
				tilecolor = AZURE;
			else
				tilecolor = return_color(cub, DARK_ORANGE);
			rect = init_rect(tile.x * cub->player.map3d.x_scale_factor,
					tile.y * cub->player.map3d.y_scale_factor,
					TILE_SIZE * cub->player.map3d.x_scale_factor,
					TILE_SIZE * cub->player.map3d.y_scale_factor);
			draw_rectangle(&cub->img, rect, tilecolor);
		}
	}
}
