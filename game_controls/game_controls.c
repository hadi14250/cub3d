/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/27 09:53:12 by hakaddou         ###   ########.fr       */
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
    BLACK_COLOR);
    render(cub);
    print_string_middle_box(cub, (WINDOW_HEIGHT / 2) - 20, WHITE_COLOR, "Hello Pretty World Hello Pretty World Hello Pretty World");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "Hello Pretty World");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "My name is hadi and I am 24 years old");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "I have a passion for eating icecream");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "one one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "one one one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos - 20, WHITE_COLOR, "one one one one one one one");
}