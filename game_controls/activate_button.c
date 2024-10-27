/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:18:21 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/27 10:37:05 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void    remove_gun(t_cub *cub)
{
    cub->button_controls.remove_machine_gun = !cub->button_controls.remove_machine_gun;
    cub->keys.c = false;
    reset_hover_state(cub->control_box.buttons);
    change_equip_button_state(cub);
}

void    reset_controls(t_cub *cub)
{
    t_original_settings original = cub->control_box.original_controls;

    cub->floor = original.floor_color;
    cub->ceiling = original.sky_color;
    cub->player.map3d.map_background_color = original.mini_map_bg_color;
    cub->player.map3d.map_wall_color = original.mini_map_wall_color;
    cub->player.map3d.map_ray_color = original.mini_map_ray_color;
    cub->keys.c = false;
    if (cub->button_controls.remove_machine_gun)
        cub->button_controls.remove_machine_gun = false;
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
    if(!ft_strncmp(hovered->str, "Reset Controls", ft_strlen(hovered->str)))
         reset_controls(cub);
}

void    activate_button(t_cub *cub)
{
    t_button *hovered;

    hovered = get_hovered_button(cub->control_box.buttons);
    if (!hovered)
        exit_cub(cub, 1, "no buttons exist\n");
        
    parse_button_functionality(hovered, cub);
}

