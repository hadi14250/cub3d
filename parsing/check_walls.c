/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:56:43 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 09:17:47 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_up(t_cub *cub, int i, int j)
{
	int	up;

	up = i;
	if (i == 0)
		exit_cub(cub, 1,
			"Error\n'0' found at the top of the map\n");
	while (up >= 0)
	{
		if (cub->map[up][j] != '\0')
		{
			if (cub->map[up][j] == '1')
				return (0);
		}
		up--;
	}
	return (1);
}

int	check_down(t_cub *cub, int i, int j)
{
	int	down;
	int	height;

	down = i;
	height = return_split_len(cub->map);
	if (i == 0)
		exit_cub(cub, 1,
			"Error\n'0' found at the top of the map\n");
	while (down < height)
	{
		if (cub->map[down][j])
		{
			if (cub->map[down][j] == '1')
				return (0);
		}
		down++;
	}
	return (1);
}

int	check_left(t_cub *cub, int i, int j)
{
	int	left;

	left = j;
	if (i == 0)
		exit_cub(cub, 1,
			"Error\n'0' found at the top of the map\n");
	while (left >= 0)
	{
		if (cub->map[i][left])
		{
			if (cub->map[i][left] == '1')
				return (0);
		}
		left--;
	}
	return (1);
}

int	check_right(t_cub *cub, int i, int j)
{
	int	right;
	int	longest;

	right = j;
	longest = get_longest_line(cub->map);
	if (i == 0)
		exit_cub(cub, 1,
			"Error\n'0' found at the top of the map\n");
	while (right < longest)
	{
		if (cub->map[i][right])
		{
			if (cub->map[i][right] == '1')
				return (0);
		}
		right++;
	}
	return (1);
}

void	all_wall_checks(t_cub *cub, int i, int j)
{
	if (check_up(cub, i, j))
		exit_cub(cub, 1, "Error\nMap is not surrounded by walls\n");
	if (check_down(cub, i, j))
		exit_cub(cub, 1, "Error\nMap is not surrounded by walls\n");
	if (check_left(cub, i, j))
		exit_cub(cub, 1, "Error\nMap is not surrounded by walls\n");
	if (check_right(cub, i, j))
		exit_cub(cub, 1, "Error\nMap is not surrounded by walls\n");
}
