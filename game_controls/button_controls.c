/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:41:43 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/11 08:48:37 by hakaddou         ###   ########.fr       */
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

void    resize_button(t_button *button)
{
    button->button_x -= BUTTON_X_SHIFT;
    button->button_w += (BUTTON_X_SHIFT * 2);
    button->button_y -= BUTTON_Y_SHIFT;
    button->button_h += (BUTTON_Y_SHIFT * 2);
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
