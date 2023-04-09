/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:01:56 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/10 03:30:58 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		exit_cub(cub, 1, "Error\ncan't init mlx\n");
	init_textures(cub);
}
