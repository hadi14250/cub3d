/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:56:43 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/12 20:56:30 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_up(t_cub *cub, int i, int j)
{
	int	up;

	up = i;
	if (i == 0)
		exit_cub(cub, 1, "Error\n'0' found at the top of the map\n");
	while (up >= 0)
	{
		if (cub->map[up][j])
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

	down = i;
	if (i == 0)
		exit_cub(cub, 1, "Error\n'0' found at the top of the map\n");
	while (cub->map[down])
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
		exit_cub(cub, 1, "Error\n'0' found at the top of the map\n");
	while (left >= 0 && cub->map[i][left])
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

	right = j;
	if (i == 0)
		exit_cub(cub, 1, "Error\n'0' found at the top of the map\n");
	while (cub->map[i][right])
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

void	check_borders(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
				all_wall_checks(cub, i, j);
			j++;
		}
		i++;
	}
}
