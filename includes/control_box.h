/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_box.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:21:17 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/30 11:48:52 by hakaddou         ###   ########.fr       */
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
	int				str_width;
	int				str_height;
    char            *str;
    int             str_len;
    int             last_button_y_pos;
    t_rect          button_rect;
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
}			t_contorl_box;

#endif
