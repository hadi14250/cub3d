/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:18:09 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/10 20:24:53 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


const int Map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool	maphaswallat(double x, double y)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	map_grid_index_x = floor(x / TILE_SIZE);
	map_grid_index_y = floor(y / TILE_SIZE);
	if (x < 0 || x > MAP_NUM_COLS * TILE_SIZE
		|| y < 0 || y > MAP_NUM_ROWS * TILE_SIZE)
		return (true);
	if ((Map[map_grid_index_y][map_grid_index_x] == 0))
		return (false);
	return (true);
}

int	get_map_at(int i, int j)
{
	return (Map[i][j]);
}

bool	is_inside_map(double x, double y)
{
	return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE
		&& y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

void	render_map(t_cub *cub)
{
	int		i;
	int		j;
	int		tilex;
	int		tiley;
	int		tilecolor;
	t_rect	rect;

	i = -1;
	j = -1;
	while (++i < MAP_NUM_ROWS)
	{
		j = -1;
		while (++j < MAP_NUM_COLS)
		{
			tilex = j * TILE_SIZE;
			tiley = i * TILE_SIZE;
			if (Map[i][j] == 1)
				tilecolor = WHITE_COLOR;
			else
				tilecolor = BLACK_COLOR;
			rect = init_rect(tilex * cub->scale_factor,
					tiley * cub->scale_factor,
					TILE_SIZE * cub->scale_factor,
					TILE_SIZE * cub->scale_factor);
			draw_rectangle(&cub->img, rect, tilecolor);
		}
	}
}