/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checks_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:20:48 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 06:21:13 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	exit_app(t_cub *cub)
{
	cub->img.img_ptr = free_img(cub->img.img_ptr, cub->mlx);
	cub->win = free_window(cub->mlx, cub->win);
	exit_cub(cub, 0, "Game finished successfully ✅\n");
	return (0);
}

void	check_anim_aim(t_cub *cub)
{
	if (cub->fps >= 0)
		animate_aim(cub);
	else
		cub->keys.aim = false;
}
