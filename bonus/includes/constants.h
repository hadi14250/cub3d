/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:15:27 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/06 17:55:29 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONSTANTS_H
# define CONSTANTS_H

# define TILE_SIZE 64

// # define TEX_WIDTH 32
// # define TEX_HEIGHT 32

# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20
 

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define PI 3.14159265
# define TWO_PI 6.283185

# define FOV_ANGLE 60 * (PI / 180)

#define WALL_STRIP_WIDTH 1

# define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH

# define MINIMAP_SCALE_FACTOR 0.3

// // texture
// # define TEXTURE_HEIGHT 			64
// # define TEXTURE_WIDTH 				64

#endif