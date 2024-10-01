/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/01 10:24:05 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_button(t_cub *cub, t_button *button)
{
	int	i;
	int	j;
    t_rect rect;

    rect = button->button_rect;
	i = button->button_x;
	j = button->button_y;
	while (i < rect.x + rect.width)
	{
		while (j < rect.y + rect.height)
		{
			my_mlx_pixel_put(&cub->img, i, j, BUTTON_COLOR);
			j++;
		}
		i++;
		j = rect.y;
	}
    // print_string_middle_box(cub, button->str_y, WHITE_COLOR, button->str);
}

void    init_button_middle(t_button *button, char *str, int y)
{
    button->last_button_y_pos = (WINDOW_HEIGHT / 2) - (BUTTON_START_DISTANCE * (button->button_num + 1));
    button->str = str;
    button->str_len = ft_strlen(str);
    button->str_x = (WINDOW_WIDTH / 2) - (button->str_len * 7.5) / 2 ;
    button->str_y = y;
    button->str_width = button->str_len * CHAR_PIXEL_WIDTH;
    button->str_height = CHAR_PIXEL_WIDTH;
    button->button_x = button->str_x ;
    button->button_y = button->last_button_y_pos - button->str_height;
    button->button_w = button->str_width;
    button->button_h = button->str_height;
}

/* int post is a flag to determine if we want to print in
the middle of the box, to the right, or left */

void    init_button(t_button *button, char *str, int pos, int y)
{
    if (pos == MID_FLAF)
        init_button_middle(button, str, y);
}


void    print_string_middle_box(t_cub *cub, int y, char *str)
{
    int len_str = ft_strlen(str);
    int x = (WINDOW_WIDTH / 2) - (len_str * CHAR_PIXEL_WIDTH) / 2 ;
    cub->control_box.last_string_y_pos = y;
    mlx_string_put(cub->mlx, cub->win, x, y, STR_COLOR, str);
}

void    init_button_nums(t_button *buttons)
{
    int i;

    i = -1;
    while(++i < BUTTON_NUM)
        buttons[i].button_num = i;
}

void    print_control_box(t_cub *cub)
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
    
    init_button_nums(cub->control_box.buttons);
    init_button(&cub->control_box.buttons[0], "test", MID_FLAF, Y_MID);

    cub->control_box.buttons[0].button_rect = init_rect(
      cub->control_box.buttons[0].button_x,
      cub->control_box.buttons[0].button_y,
      cub->control_box.buttons[0].button_w,
      cub->control_box.buttons[0].button_h  
    );

    draw_button(
            cub,
            &cub->control_box.buttons[0]
        );

    render(cub);

    print_string_middle_box(
        cub,
        cub->control_box.buttons[0].last_button_y_pos + BUTTON_VERTICAL_DISTANCE * cub->control_box.buttons[0].button_num,
        cub->control_box.buttons[0].str
        );



    // print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one");
    // print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one");
    // print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one one");
    // print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one one one");
    // print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one one one one");
    // print_string_middle_box(cub, cub->control_box.last_string_y_pos + 50, WHITE_COLOR, "one one one one one one one");
    // task for tmrw : print a box behind each string to make it look like a button
}