/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadikaddoura <hadikaddoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:18:21 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/18 22:14:12 by hadikaddour      ###   ########.fr       */
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

void    change_ground_color_random(t_cub *cub)
{
    cub->floor = get_random_color();
}

void    change_sky_color_random(t_cub *cub)
{
    cub->ceiling = get_random_color();
}

void    change_minimap_backgound_color_random(t_cub *cub)
{
    cub->player.map3d.map_background_color = get_random_color();
}

void    change_minimap_wall_color_random(t_cub *cub)
{
    cub->player.map3d.map_wall_color = get_random_color();
}

void    change_minimap_ray_color_random(t_cub *cub)
{
    cub->player.map3d.map_ray_color = get_random_color();
}

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

void    remove_gun(t_cub *cub)
{
    cub->button_controls.remove_machine_gun = !cub->button_controls.remove_machine_gun;
    cub->keys.c = false;
    reset_hover_state(cub->control_box.buttons);
    change_equip_button_state(cub);
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
    if(!ft_strncmp(hovered->str, "Change Ground Color (random)", ft_strlen(hovered->str)))
        change_ground_color_random(cub);
    if(!ft_strncmp(hovered->str, "Change Sky Color (random)", ft_strlen(hovered->str)))
        change_sky_color_random(cub);
    if(!ft_strncmp(hovered->str, "Change Minmap Background Color (random)", ft_strlen(hovered->str)))
        change_minimap_backgound_color_random(cub);
    if(!ft_strncmp(hovered->str, "Change Minimap Wall Color (random)", ft_strlen(hovered->str)))
        change_minimap_wall_color_random(cub);
    if(!ft_strncmp(hovered->str, "Change Minmap Ray Color (random)", ft_strlen(hovered->str)))
        change_minimap_ray_color_random(cub);
    if(!ft_strncmp(hovered->str, "Un Equip Gun", ft_strlen(hovered->str)) ||
        !ft_strncmp(hovered->str, "Re Equip Gun", ft_strlen(hovered->str)))
        remove_gun(cub);
}

void    activate_button(t_cub *cub)
{
    t_button *hovered;

    hovered = get_hovered_button(cub->control_box.buttons);
    if (!hovered)
        exit_cub(cub, 1, "no buttons exist\n");
        
    parse_button_functionality(hovered, cub);
}

