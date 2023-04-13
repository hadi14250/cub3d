/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:06:46 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 06:55:07 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// takes a circle struct and draws it the the image inputed as argument,
//the circle needs to be initialised using the init_circle() function
// before passing it here
void	draw_circle(t_img *img, t_circle circle, int color)
{
	int	i;
	int	j;
	int	radius_squared;

	radius_squared = circle.radius * circle.radius;
	i = -circle.radius;
	while (i <= circle.radius)
	{
		j = -circle.radius;
		while (j <= circle.radius)
		{
			if ((i * i) + (j * j) <= radius_squared)
				my_mlx_pixel_put(img, circle.x + i, circle.y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_bressen_line(t_img *img, t_point start, t_point end, int color)
{
	int	dx;
	int	dy;

	if (color == 0)
		color = 0xffffff;
	dx = absolute (start.x - end.x);
	dy = absolute (start.y - end.y);
	if (dy < dx)
	{
		if (start.x > end.x)
		{
			ft_swap(&start.x, &end.x);
			ft_swap(&start.y, &end.y);
			ft_drawlinex(img, start, end, color);
		}
		else
			ft_drawlinex(img, start, end, color);
	}
	else
		help_for_draw(img, start, end, color);
}

// initialises the t_point struct x and y members to the arguments inputed
void	init_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

// initialises the t_circle struct x and y and
// radius members to the arguments inputed
void	init_circle(t_circle *circle, int x, int y, int radius)
{
	circle->radius = radius;
	circle->x = x;
	circle->y = y;
}
