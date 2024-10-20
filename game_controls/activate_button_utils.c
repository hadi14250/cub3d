/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_button_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadikaddoura <hadikaddoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:26:42 by hadikaddour       #+#    #+#             */
/*   Updated: 2024/10/20 22:29:11 by hadikaddour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    change_equip_button_state(t_cub *cub)
{
    int     i;
    char    **txt;

    i = 0;
    txt = cub->control_box.buttons_txt;
    while(txt[i] != NULL)
    {
        if(!ft_strncmp(txt[i], "Un Equip Gun", ft_strlen(txt[i])))
        {
            free(txt[i]);
            txt[i] = ft_strdup("Re Equip Gun");
            break;
        }
        else if (!ft_strncmp(txt[i], "Re Equip Gun", ft_strlen(txt[i])))
        {
            free(txt[i]);
            txt[i] = ft_strdup("Un Equip Gun");
            break;
        }
        i++;
    }
}

t_button *get_hovered_button(t_button *buttons)
{
    int i;

    i = -1;
    while(++i < BUTTON_NUM && buttons[i].str != NULL && buttons[i].hovered == false)
        ;
    if (i >= 0 && i < BUTTON_NUM && buttons[i].str != NULL)
        return(&buttons[i]);
    if (buttons[0].str != NULL)
        return (&buttons[0]);
    return(NULL);
}

unsigned int get_random_color()
{
    unsigned int    red;
    unsigned int    green;
    unsigned int    blue;
    unsigned int    color;

    red = rand() % 256;
    green = rand() % 256;
    blue = rand() % 256;
    color = (red << 16) | (green << 8) | blue;
    return(color);
}
