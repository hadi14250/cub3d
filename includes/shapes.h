/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:14:36 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/03 23:35:33 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHAPES_H
# define SHAPES_H

typedef struct s_point
{
	double			x;
	double			y;
}			t_point;

typedef struct s_circle
{
	int				x;
	int				y;
	int				radius;
}			t_circle;

typedef struct s_rect
{
	int				x;
	int				y;
	int				width;
	int				height;
}			t_rect;

#endif