/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bressen_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:38:35 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/11 22:40:12 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_drawlinex(t_img *img, t_point start, t_point end, int color)
{
	int	index[4];

	index[2] = end.x - start.x;
	index[3] = end.y - start.y;
	index[1] = 1;
	if (index[3] < 0)
	{
		index[1] = -1;
		index[3] *= -1;
	}
	index[0] = (2 * index[3]) - index[2];
	while (start.x < end.x)
	{
		my_mlx_pixel_put(img, start.x, start.y, color);
		if (index[0] > 0)
		{
			start.y += index[1];
			index[0] += 2 * (index[3] - index[2]);
		}
		else
			index[0] += 2 * index[3];
		start.x++;
	}
}

void	ft_drawliney(t_img *img, t_point start, t_point end, int color)
{
	int	index[4];

	index[2] = end.x - start.x;
	index[3] = end.y - start.y;
	index[1] = 1;
	if (index[2] < 0)
	{
		index[1] = -1;
		index[2] *= -1;
	}
	index[0] = (2 * index[2]) - index[3];
	while (start.y < end.y)
	{
		my_mlx_pixel_put(img, start.x, start.y, color);
		if (index[0] > 0)
		{
			start.x += index[1];
			index[0] += 2 * (index[2] - index[3]);
		}
		else
			index[0] += 2 * index[2];
		start.y++;
	}
}

long	absolute(long num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

void	help_for_draw(t_img *img, t_point start, t_point end, int color)
{
	if (start.y > end.y)
	{
		ft_swap(&start.x, &end.x);
		ft_swap(&start.y, &end.y);
		ft_drawliney(img, start, end, color);
	}
	else
		ft_drawliney(img, start, end, color);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x <= 0 || y <= 0)
		return ;
	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	dst = img->address + offset;
	*(unsigned int *)dst = color;
}
