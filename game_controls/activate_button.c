/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadikaddoura <hadikaddoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:18:21 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/15 23:29:50 by hadikaddour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_button *get_hovered_button(t_button *buttons)
{
    int i;

    i = -1;
    while(++i < BUTTON_NUM && buttons[i].str != NULL && buttons[i].hovered == false)
        ;
    if (i >= 0 && buttons[i].str != NULL)
        return(&buttons[i]);
    if (buttons[0].str != NULL)
        return (&buttons[0]);
    return(NULL);
}


void    print_black_box(t_cub *cub)
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

    printf("entered here\n");

    printf("%s\n", get_hovered_button(cub->control_box.buttons)->str);
    // intit_all_buttons(cub->control_box.buttons);
    
    // draw_all_buttons(cub->control_box.buttons, cub);
}


void    activate_button(t_cub *cub)
{
    t_button *hovered;

    hovered = get_hovered_button(cub->control_box.buttons);
    if (!hovered)
        exit_cub(cub, 1, "no buttons exist\n");
        
    // parse_button_functionality(hovered, cub);

    // cub->button_controls.remove_machine_gun = !cub->button_controls.remove_machine_gun;
    // cub->keys.c = false;
}

