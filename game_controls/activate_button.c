/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:18:21 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/17 08:33:46 by hakaddou         ###   ########.fr       */
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

void    parse_button_functionality(t_button *hovered, t_cub *cub)
{
    if(!ft_strncmp(hovered->str, "Exit Game", ft_strlen(hovered->str)))
        exit_app(cub);
    if(!ft_strncmp(hovered->str, "Exit Controls", ft_strlen(hovered->str)))
    {
        reset_hover_state(cub->control_box.buttons);
        cub->keys.c = false;
    }
}

void    activate_button(t_cub *cub)
{
    t_button *hovered;

    hovered = get_hovered_button(cub->control_box.buttons);
    if (!hovered)
        exit_cub(cub, 1, "no buttons exist\n");
        
    parse_button_functionality(hovered, cub);

    // cub->button_controls.remove_machine_gun = !cub->button_controls.remove_machine_gun;
    // cub->keys.c = false;
}

