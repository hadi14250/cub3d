/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:15:27 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/11 08:45:15 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# include "../cub3d.h"

# define TILE_SIZE 64

// # define TEX_WIDTH 32
// # define TEX_HEIGHT 32

# define AIM_ZOOM_FPS 20
# define AIM_ZOOM_INCREMENT 0.1

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 832

# define PI 3.14159265
# define TWO_PI 6.283185

# define FOV_ANGLE 60

# define NUM_RAYS WINDOW_WIDTH

# define MINIMAP_SCALE_FACTOR 0.3

# define BUTTON_NUM 30

# define X_MID WINDOW_WIDTH / 2

# define Y_MID WINDOW_HEIGHT / 2

# define MID_FLAG 0

# define CHAR_PIXEL_WIDTH 7.3

# define BUTTON_START_DISTANCE 200

# define BUTTON_VERTICAL_DISTANCE 50

# define BUTTON_COLOR RED_COLOR
# define STR_COLOR    WHITE_COLOR
#define HOVER_COLOR BLUE_COLOR

# define BUTTON_X_SHIFT 25
# define BUTTON_Y_SHIFT 10

#define ROUNDED_BUTTONS true

#endif
