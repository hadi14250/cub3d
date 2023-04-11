/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:18:09 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/12 02:28:05 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void render_map(t_cub *cub)
{
    int tile_color;
    t_rect rect;
    float rect_width = (float)(WINDOW_WIDTH * cub->scale_factor) / (float)(cub->player.map3d.width);
    float rect_height = (float)(WINDOW_HEIGHT * cub->scale_factor) / (float)(cub->player.map3d.height);

    for (int y = 0; y < cub->player.map3d.height; y++) {
        for (int x = 0; x < cub->player.map3d.width; x++) {
            float rect_x = x * rect_width;
            float rect_y = y * rect_height;

            if (cub->player.map3d.map[y][x] == '1')
                tile_color = WHITE_COLOR;
            else
                tile_color = BLACK_COLOR;

            rect = init_rect(rect_x, rect_y, rect_width, rect_height);
            draw_rectangle(&cub->img, rect, tile_color);
        }
    }
}

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

// void	render_map(t_cub *cub)
// {
// 	int		i;
// 	int		j;
// 	int		tilex;
// 	int		tiley;
// 	int		tilecolor;
// 	t_rect	rect;

// 	i = -1;
// 	j = -1;
// 	while (++i < cub->player.map3d.height)
// 	{
// 		j = -1;
// 		while (++j < cub->player.map3d.width)
// 		{
// 			tilex = j * TILE_SIZE;
// 			tiley = i * TILE_SIZE;
// 			if (cub->player.map3d.map[i][j] == '1')
// 				tilecolor = WHITE_COLOR;
// 			else
// 				tilecolor = BLACK_COLOR;
// 			rect = init_rect(tilex * cub->scale_factor,
// 					tiley * cub->scale_factor,
// 					TILE_SIZE * cub->scale_factor,
// 					TILE_SIZE * cub->scale_factor);
// 			draw_rectangle(&cub->img, rect, tilecolor);
// 		}
// 	}
// }