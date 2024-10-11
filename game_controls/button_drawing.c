/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:43:20 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/11 08:49:49 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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