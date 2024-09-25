/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/25 10:21:40 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    print_control_box(t_cub *cub)
{
    int     width = WINDOW_WIDTH / 1.6;
    int     height = WINDOW_HEIGHT / 1.6;
    int x = WINDOW_WIDTH /  5.6;
    int y = WINDOW_HEIGHT / 5.6;
    t_rect controls_rect;

    controls_rect = init_rect(x, y, width, height);
    draw_rectangle(&cub->img, controls_rect, BLACK_COLOR);
    render(cub);
    
    // maybe use strlen to make the string actually print in the middle
    mlx_string_put(cub->mlx, cub->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WHITE_COLOR, "Hello Pretty World");
}