/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_box.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadikaddoura <hadikaddoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:21:17 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/15 22:53:42 by hadikaddour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_BOX_H
# define CONTROL_BOX_H

# include "../cub3d.h"

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
    int     width;
    int     height;
    int     x;
    int     y;
    t_rect  controls_rect;
    t_button  buttons[BUTTON_NUM];
    int     last_string_y_pos;
    bool    down_arrow;
    bool    down_arrow_released;
}			t_contorl_box;

#endif
