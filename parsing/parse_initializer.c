/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:01:56 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/07 14:48:05 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_cub *cub)
{
	//void	*temp;
	cub->mlx = mlx_init();
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
	if (validate_map(cub) == 1)
	{
		printf("error in map\n");
		exit(1);
	}
}
