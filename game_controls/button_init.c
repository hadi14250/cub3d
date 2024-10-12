/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:44:48 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/11 08:50:45 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    intit_all_buttons(t_button *buttons)
{
    init_button_nums(buttons);

    init_button(&buttons[0], "Change Gun", MID_FLAG, Y_MID);
    init_button(&buttons[1], "Remove Gun", MID_FLAG, Y_MID);
    init_button(&buttons[2], "Change Ground Color (random)", MID_FLAG, Y_MID);
    init_button(&buttons[3], "Change Sky Color (random)", MID_FLAG, Y_MID);
    init_button(&buttons[4], "Change Map Background Color", MID_FLAG, Y_MID);
    init_button(&buttons[5], "Change Map Wall Color", MID_FLAG, Y_MID);
    init_button(&buttons[6], "Change Map Ray Color", MID_FLAG, Y_MID);

    update_max_button_num(buttons);

    mark_hovered_button(buttons);
}

void    init_button_middle(t_button *button, char *str, int y)
{
    button->str = str;
    button->str_len = ft_strlen(str);
    button->str_x = (WINDOW_WIDTH / 2) - (button->str_len * 7.5) / 2 ;
    button->str_y = y;
    button->str_width = button->str_len * CHAR_PIXEL_WIDTH;
    button->str_height = CHAR_PIXEL_WIDTH;
    button->button_x = button->str_x;
    button->button_y = button->last_button_y_pos - button->str_height;
    button->button_w = button->str_width;
    button->button_h = button->str_height;
    button->color = BUTTON_COLOR;
    resize_button(button);
}

/* int post is a flag to determine if we want to print in
the middle of the box, to the right, or left */

void    init_button(t_button *button, char *str, int pos, int y)
{
    if (pos == MID_FLAG)
        init_button_middle(button, str, y);
}

void init_button_nums(t_button *buttons)
{
    int i;

    i = -1;
    while (++i < BUTTON_NUM)
    {
        buttons[i].button_num = i;
        if (i == 0)
            buttons[i].last_button_y_pos = (WINDOW_HEIGHT / 2) - (BUTTON_START_DISTANCE);
        else
            buttons[i].last_button_y_pos = buttons[i - 1].last_button_y_pos + BUTTON_VERTICAL_DISTANCE;
        buttons[i].str = NULL;
    }
}
