/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:53 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/26 10:59:42 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    print_string(t_cub *cub, char *str)
{
    // int width = cub->control_box.width;
    // int height = cub->control_box.height;
    int len_str = ft_strlen(str);
    // int x = cub->control_box.x + (cub->control_box.width / 2) - (len_str);
    int x = (WINDOW_WIDTH / 2) - len_str * 3 ;
    // printf("len_str is: %d\n", len_str);
    // int y = cub->control_box.y;
    
    mlx_string_put(cub->mlx, cub->win, x, WINDOW_HEIGHT / 2, WHITE_COLOR, str);
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
    BLACK_COLOR);
    render(cub);
    // print_string(cub, "Hello Pretty World Hello Pretty World Hello Pretty World");
    mlx_string_put(cub->mlx, cub->win, 0, WINDOW_HEIGHT / 2, WHITE_COLOR,
    "1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100"
    );
    printf("Length is: %zu\n",
    ft_strlen("1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100"));
}