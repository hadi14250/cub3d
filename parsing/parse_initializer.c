/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:01:56 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/04 16:16:57 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_cub *game)
{
	//void	*temp;
	game->mlx = mlx_init();
	if (init_textures(game) == 1)
	{
		printf("Cannot load textures\n");
		exit(1);
	}
	if (init_colors(game) == 1)
	{
		printf("cannot load colours\n");
		exit(1);
	}
	if (validate_map(game) == 1)
	{
		printf("error in map\n");
		exit(1);
	}
}
