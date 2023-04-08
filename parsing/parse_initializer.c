/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:01:56 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/08 13:22:14 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		exit_cub(cub, 1, "Error\ncan't init mlx\n");
	if (init_textures(cub) == 1)
	{
		printf("Cannot load textures\n");
		exit(1);
	}
	if (init_colors(cub) == 1)
	{
		printf("cannot load colours\n");
		exit(1);
	}
	init_textures(cub);
	// if (validate_map(cub) == 1)
	// {
	// 	printf("error in map\n");
	// 	exit(1);
	// }
}
