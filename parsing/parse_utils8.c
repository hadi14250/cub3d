/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:12:51 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 09:15:42 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_for_walls(t_cub *cub)
{
	int	i;
	int	j;
	int	wall_flag;

	i = 0;
	wall_flag = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
			{
				wall_flag = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	if (!wall_flag)
		exit_cub(cub, 1, "Error\nNo walls found\n");
}

void	get_player_index(t_cub *cub, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E'
				|| cub->map[i][j] == 'S' || cub->map[i][j] == 'W')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}

void	check_map_lines(t_cub *cub)
{
	int	lines;

	lines = return_split_len(cub->map);
	if (lines <= 2)
		exit_cub(cub, 1, "Error\nMap cannot be less than 2 lines\n");
	return ;
}

void	check_pos_helper2(t_cub *cub)
{
	int		i;
	char	**split;

	split = cub->map;
	i = -1;
	while (split[++i] != NULL)
	{
		if (ft_strnstr(split[i], "EA", ft_strlen(split[i])))
		{
			cub->ea_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
		if (ft_strnstr(split[i], "WE", ft_strlen(split[i])))
		{
			cub->we_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
	}
}

void	check_positions(t_cub *cub)
{
	int		i;
	char	**split;

	cub->max = 0;
	split = cub->map;
	i = -1;
	while (split[++i] != NULL)
	{
		if (ft_strnstr(split[i], "NO", ft_strlen(split[i])))
		{
			cub->no_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
		if (ft_strnstr(split[i], "SO", ft_strlen(split[i])))
		{
			cub->so_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
	}
	check_pos_helper(cub);
	check_pos_helper2(cub);
	check_map_pos(cub, &cub->map[cub->max + 1]);
}
