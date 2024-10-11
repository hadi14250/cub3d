/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:45:59 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/11 08:52:01 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    print_string_middle_box(t_cub *cub, int y, char *str)
{
    int len_str = ft_strlen(str);
    int x = (WINDOW_WIDTH / 2) - (len_str * CHAR_PIXEL_WIDTH) / 2 ;
    mlx_string_put(cub->mlx, cub->win, x, y, STR_COLOR, str);
}

void    print_all_strings(t_button *buttons, t_cub *cub)
{
    int i;

    i = -1;
    while(++i < BUTTON_NUM)
    {
        if (buttons[i].str_len > 0)
        {
            print_string_middle_box(
                cub,
                buttons[i].last_button_y_pos,
                buttons[i].str
                );
        }
    }

}
