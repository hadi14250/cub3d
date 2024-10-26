/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_box.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:21:17 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/26 10:10:17 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_BOX_H
# define CONTROL_BOX_H

# include "../cub3d.h"
# include "./button_vars.h"

typedef struct s_original_settings {
    void    *gun;
    int     sky_color;
    int     floor_color;
    int     mini_map_bg_color;
    int     mini_map_wall_color;
    int     mini_map_ray_color;
}   t_original_settings;

typedef struct s_button
{
	int				button_x;
	int				button_y;
	int				str_x;
	int				str_y;
	int				button_w;
	int				button_h;
	double				str_width;
	double				str_height;
    char            *str;
    int             str_len;
    int             last_button_y_pos;
    int             button_num;
    t_rect          button_rect;
    int             color;
    int             str_color;
    bool            hovered;
    int             max_buttons;
}			t_button;

typedef struct s_contorl_box
{
    int                 width;
    int                 height;
    int                 x;
    int                 y;
    t_rect              controls_rect;
    t_button            buttons[BUTTON_NUM];
    int                 last_string_y_pos;
    bool                down_arrow;
    bool                down_arrow_released;
    char                **buttons_txt;
    t_original_settings original_controls;
}			t_contorl_box;

#endif
