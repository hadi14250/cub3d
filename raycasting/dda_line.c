/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:31:07 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/10 21:50:36 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_dda_line(t_img *img, t_point start, t_point end, int color)
{
	t_point	delta;
	int		longest;
	t_point	inc;
	t_point	current;
	int		i;

	init_point(&delta, (end.x - start.x), (end.y - start.y));	
	longest = (absolute(delta.x) >= absolute(delta.y)) ? absolute(delta.x) : absolute(delta.y);
	init_point(&inc, (delta.x / (float)longest), (delta.y / (float)longest));
	init_point(&current, start.x, start.y);
	i = -1;
	while (++i < longest)
	{
		my_mlx_pixel_put(img, round(current.x), round(current.y), color);
		current.x += inc.x;
		current.y += inc.y;
	}
}