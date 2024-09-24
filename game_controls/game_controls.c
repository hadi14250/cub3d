/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/24 10:13:43 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    print_control_box(t_cub *cub)
{
    t_rect controls_rect;
    controls_rect = init_rect(500, 500, 500, 500);
    draw_rectangle(&cub->img, controls_rect, BLACK_COLOR);
    render(cub);
    // mlx_string_put(cub->mlx, cub->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, BLACK_COLOR, "Hello Pretty World");
}