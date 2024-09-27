/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/27 10:10:37 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    print_string_middle_box(t_cub *cub, int y, int color, char *str)
{
    int len_str = ft_strlen(str);
    int x = (WINDOW_WIDTH / 2) - (len_str * 7.5) / 2 ;
    cub->control_box.last_string_y_pos = y;
    mlx_string_put(cub->mlx, cub->win, x, y, color, str);
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
    TRANSPARENT_BLACK_COLOR);
    render(cub);
    cub->control_box.last_string_y_pos = (WINDOW_HEIGHT / 2) - 200;
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 20, WHITE_COLOR, "one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 20, WHITE_COLOR, "one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 20, WHITE_COLOR, "one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 20, WHITE_COLOR, "one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 20, WHITE_COLOR, "one one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 20, WHITE_COLOR, "one one one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 20, WHITE_COLOR, "one one one one one one one");
    // task for tmrw : print a box behind each string to make it look like a button
}