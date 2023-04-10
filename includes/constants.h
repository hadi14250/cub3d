/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:15:27 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/10 19:46:26 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONSTANTS_H
# define CONSTANTS_H

#include "../cub3d.h"

# define TILE_SIZE 64

// # define TEX_WIDTH 32
// # define TEX_HEIGHT 32

# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20


# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 800

# define PI 3.14159265
# define TWO_PI 6.283185

# define FOV_ANGLE 60 * (PI / 180)

#define WALL_STRIP_WIDTH 1

# define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH

# define MINIMAP_SCALE_FACTOR 0.3

# define DIST_PROJ_PLANE ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2))

// // texture
// # define TEXTURE_HEIGHT 			64
// # define TEXTURE_WIDTH 				64

#endif
