/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/30 11:31:08 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    init_button_middle(t_button *button, char *str, int color, int y)
{
    button->str = str;
    button->str_len = ft_strlen(str);
    button->str_x = (WINDOW_WIDTH / 2) - (button->str_len * 7.5) / 2 ;
    button->str_y = y;
    button->last_button_y_pos = y;
    button->color = color;
    button->str_width = button->str_len * CHAR_PIXEL_WIDTH;
    button->str_height = CHAR_PIXEL_WIDTH;
}

/* int post is a flag to determine if we want to print in
the middle of the box, to the right, or left */

void    init_button(t_button *button, char *str, int pos, int color, int y)
{
    if (pos == MID_FLAF)
        init_button_middle(button, str, color, y);
}


void    print_string_middle_box(t_cub *cub, int y, int color, char *str)
{
    int len_str = ft_strlen(str);
    int x = (WINDOW_WIDTH / 2) - (len_str * CHAR_PIXEL_WIDTH) / 2 ;
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
    
    init_button(&cub->control_box.buttons[0], "test test test test ", MID_FLAF, RED_COLOR, Y_MID);

    cub->control_box.buttons[0].button_rect = init_rect(
      cub->control_box.buttons[0].str_x,
      cub->control_box.buttons[0].str_y,
      cub->control_box.buttons[0].str_width,
      cub->control_box.buttons[0].str_height  
    );

    draw_rectangle(
            &cub->img,
            cub->control_box.buttons[0].button_rect,
            cub->control_box.buttons[0].color
        );

printf("Button X: %d, Y: %d, Width: %d, Height: %d\n", 
    cub->control_box.buttons[0].str_x, 
    cub->control_box.buttons[0].str_y, 
    cub->control_box.buttons[0].str_width, 
    cub->control_box.buttons[0].str_height);


    render(cub);


    cub->control_box.last_string_y_pos = (WINDOW_HEIGHT / 2) - 200;
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one one one one");
    print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one one one one one");
    // task for tmrw : print a box behind each string to make it look like a button
}