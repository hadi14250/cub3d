/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadikaddoura <hadikaddoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:44:48 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/18 21:56:02 by hadikaddour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    get_button_txt(t_button *buttons, t_cub *cub)
{
    int     i;
    char    *str;
    int     fd;
    int     j;

    fd = open("./game_controls/button_txt.txt", O_RDONLY);
    if(fd < 0)
        return ;
    i = 0;
    str = "h";
    while(str && i < BUTTON_NUM)
    {
        str = get_next_line(fd);
        init_button(&buttons[i], str, MID_FLAG, Y_MID);
        i++;
    }
    close(fd);
    cub->control_box.buttons_txt = malloc(sizeof(char *) * i + 1);
    cub->control_box.buttons_txt[i] = NULL;
    j = 0;
    while(j < i)
    {
        cub->control_box.buttons_txt[j] = buttons[j].str;
        j++;
    }
}

void    get_saved_button_txt(t_button *buttons, t_cub *cub)
{
    int     i;

    i = -1;
    while(++i < BUTTON_NUM)
        init_button(&buttons[i], cub->control_box.buttons_txt[i], MID_FLAG, Y_MID);
}

void    intit_all_buttons(t_button *buttons, t_cub *cub)
{
    init_button_nums(buttons);

    get_saved_button_txt(buttons, cub);
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
