/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/11 08:38:24 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    inc_button_hover(t_button *buttons)
{
    int i;

    i = -1;
    while(++i < BUTTON_NUM && buttons[i].str != NULL && buttons[i].hovered == false)
        ;
    buttons[i].hovered = false;
    if (i + 1 < BUTTON_NUM && buttons[i + 1].str != NULL)
        buttons[i + 1].hovered = true;
    else if (i  == buttons[0].max_buttons)
    {
        buttons[0].hovered = false;
        buttons[1].hovered = true;
    }
    else
        buttons[0].hovered = true;
}

void    dec_button_hover(t_button *buttons)
{
    int i;
    int last_registered_button;

    last_registered_button = 0;
    i = 0;
    while(i < BUTTON_NUM && buttons[i].str != NULL)
    {
        if (buttons[i].hovered == true)
            break;
        i++;
    }

    buttons[i].hovered = false;
    
    if (i - 1 >= 0 && buttons[i - 1].str != NULL)
        buttons[i - 1].hovered = true;
    else
    {
        while(last_registered_button < BUTTON_NUM && buttons[last_registered_button].str != NULL)
            last_registered_button++;
        buttons[last_registered_button - 1].hovered = true;
    }
}

void    change_hover_state(t_button *buttons, int key)
{
    if (key == DOWN_AROW)
        inc_button_hover(buttons);
    else
        dec_button_hover(buttons);
}

void draw_button(t_cub *cub, t_button *button)
{
    int     i;
    int     j;
    t_rect  rect;
    int     center_x;
    int     center_y;
    int     dx;
    int     dy;
    int     r_squared;
    int     radius;

    radius = 10 * ROUNDED_BUTTONS;
    r_squared = radius * radius;
    rect = button->button_rect;    
    i = rect.x + radius;
    while (i < rect.x + rect.width - radius)
    {
        j = rect.y;
        while (j < rect.y + rect.height)
            my_mlx_pixel_put(&cub->img, i, j++, button->color);
        i++;
    }
    i = rect.x;
    while (i < rect.x + rect.width)
    {
        j = rect.y + radius;
        while (j < rect.y + rect.height - radius)
            my_mlx_pixel_put(&cub->img, i, j++, button->color);
        i++;
    }
    center_x = rect.x + radius;
    center_y = rect.y + radius;
    i = 0;
    while (i < radius)
    {
        j = 0;
        while (j < radius)
        {
            dx = i - radius;
            dy = j - radius;
            if (dx * dx + dy * dy <= r_squared)
                my_mlx_pixel_put(&cub->img, center_x + dx, center_y + dy, button->color);
            j++;
        }
        i++;
    }

    center_x = rect.x + rect.width - radius;
    i = 0;
    while (i < radius)
    {
        j = 0;
        while (j < radius)
        {
            dx = i;
            dy = j - radius;
            if (dx * dx + dy * dy <= r_squared)
                my_mlx_pixel_put(&cub->img, center_x + dx, rect.y + j, button->color);
            j++;
        }
        i++;
    }
    center_x = rect.x + radius;
    center_y = rect.y + rect.height - radius;
    i = 0;
    while (i < radius)
    {
        j = 0;
        while (j < radius)
        {
            dx = i - radius;
            dy = j;
            if (dx * dx + dy * dy <= r_squared)
                my_mlx_pixel_put(&cub->img, center_x + dx, center_y + dy, button->color);
            j++;
        }
        i++;
    }
    center_x = rect.x + rect.width - radius;
    i = 0;
    while (i < radius)
    {
        j = 0;
        while (j < radius)
        {
            dx = i;
            dy = j;
            if (dx * dx + dy * dy <= r_squared)
                my_mlx_pixel_put(&cub->img, center_x + dx, center_y + dy, button->color);
            j++;
        }
        i++;
    }
}

void    resize_button(t_button *button)
{
    button->button_x -= BUTTON_X_SHIFT;
    button->button_w += (BUTTON_X_SHIFT * 2);
    button->button_y -= BUTTON_Y_SHIFT;
    button->button_h += (BUTTON_Y_SHIFT * 2);
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
    if (pos == MID_FLAF)
        init_button_middle(button, str, y);
}

void    print_string_middle_box(t_cub *cub, int y, char *str)
{
    int len_str = ft_strlen(str);
    int x = (WINDOW_WIDTH / 2) - (len_str * CHAR_PIXEL_WIDTH) / 2 ;
    mlx_string_put(cub->mlx, cub->win, x, y, STR_COLOR, str);
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

void    draw_all_buttons(t_button *buttons, t_cub *cub)
{
    int i;

    i = -1;
    while(++i < BUTTON_NUM)
    {
        if (buttons[i].str_len <= 0)
            break;
        buttons[i].button_rect = init_rect(
        buttons[i].button_x,
        buttons[i].button_y,
        buttons[i].button_w,
        buttons[i].button_h  
        );
        draw_button(
                cub,
                &cub->control_box.buttons[i]
            );
    }
}

void    print_all_strings(t_button *buttons, t_cub *cub)
{
    int i;

    i = -1;
    while(++i < BUTTON_NUM)
    {
        if (buttons[i].str_len > 0)
        {
            print_string_middle_box(
                cub,
                buttons[i].last_button_y_pos,
                buttons[i].str
                );
        }
    }

}

void    mark_hovered_button(t_button *buttons)
{
    int i;

    i = 0;
    while(i < BUTTON_NUM && buttons[i].str != NULL)
    {
        if (buttons[i].hovered == true)
            break ;
        i++;
    }
    if (i < BUTTON_NUM && buttons[i].str != NULL)
        buttons[i].color = HOVER_COLOR;
    else
        buttons[0].color = HOVER_COLOR;
}
void    update_max_button_num(t_button *buttons)
{
    int i;
    int j;

    j = -1;
    i = -1;
    while (++i < BUTTON_NUM && buttons[i].str != NULL)
        ;
    while (++j < BUTTON_NUM && buttons[j].str != NULL)
        buttons[j].max_buttons = i;
}

void    intit_all_buttons(t_button *buttons)
{
    init_button_nums(buttons);

    init_button(&buttons[0], "Hello World 1 2 3 4", MID_FLAF, Y_MID);
    init_button(&buttons[1], "My Name is Hadi And I am 24 years old", MID_FLAF, Y_MID);
    init_button(&buttons[2], "42 Abu Dhabi", MID_FLAF, Y_MID);
    init_button(&buttons[3], "Testing Testing", MID_FLAF, Y_MID);
    init_button(&buttons[4], "SOS", MID_FLAF, Y_MID);
    init_button(&buttons[5], "Need button to look rounded", MID_FLAF, Y_MID);
    init_button(&buttons[6], "how?", MID_FLAF, Y_MID);
    init_button(&buttons[7], "idk", MID_FLAF, Y_MID);

    update_max_button_num(buttons);

    mark_hovered_button(buttons);
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

    intit_all_buttons(cub->control_box.buttons);
    
    draw_all_buttons(cub->control_box.buttons, cub);
}

void    redraw_button(t_button *button, t_cub *cub)
{
    if (button->str_len <= 0)
        return ;
    button->button_rect = init_rect(
    button->button_x,
    button->button_y,
    button->button_w,
    button->button_h  
    );
    draw_button(
            cub,
            button
        );
}