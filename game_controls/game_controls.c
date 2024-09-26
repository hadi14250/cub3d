/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/26 10:48:29 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    print_string(t_cub *cub, char *str)
{
    // int width = cub->control_box.width;
    // int height = cub->control_box.height;
    int len_str = ft_strlen(str);
    // int x = cub->control_box.x + (cub->control_box.width / 2) - (len_str);
    int x = (WINDOW_WIDTH / 2) - len_str * 4 ;
    // printf("len_str is: %d\n", len_str);
    // int y = cub->control_box.y;
    
    mlx_string_put(cub->mlx, cub->win, x, WINDOW_HEIGHT / 2, WHITE_COLOR, str);
}

void    print_control_box(t_cub *cub)
{
    cub->control_box.width = WINDOW_WIDTH / 1.6;
    cub->control_box.height = WINDOW_HEIGHT / 1.6;
    cub->control_box.x = WINDOW_WIDTH /  5.6;
    cub->control_box.y = WINDOW_HEIGHT / 5.6;

    cub->control_box.controls_rect = init_rect(
        cub->control_box.x,
        cub->control_box.y,
        cub->control_box.width,
        cub->control_box.height
        );
    draw_rectangle(
        &cub->img,
    cub->control_box.controls_rect,
    BLACK_COLOR);
    render(cub);
    print_string(cub, "Hello Pretty World Hello Pretty World Hello Pretty World");
}