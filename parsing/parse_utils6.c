/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:14:42 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/10 18:15:30 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_spaces(char *str)
{
	int	i;
	int	d;

	i = -1;
	d = 0;
	while (str[++i] != '\0')
	{
		if ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
			d++;
	}
	if (d != i)
		return (1);
	return (0);
}

void	check_other_format(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->map[++i] != NULL && i <= cub->max)
	{
		if (i != cub->no_pos && i != cub->ea_pos
			&& i != cub->so_pos && i != cub->we_pos
			&& i != cub->floor_pos && i != cub->ceiling_pos)
		{
			if (check_spaces(cub->map[i]))
			{
				printf("Error\nposition %d: invalid format: -->%s<--\n",
					i + 1, cub->map[i]);
				exit_cub(cub, 1, "");
			}
		}
	}
}

void	check_player_format_two(t_cub *cub)
{
	int	i;

	i = -1;
	cub->dir.west = 0;
	cub->dir.east = 0;
	while (cub->map_1d[++i] != '\0')
	{
		if (cub->map_1d[i] == 'E')
			cub->dir.east++;
		else if (cub->map_1d[i] == 'W')
			cub->dir.west++;
	}
	if ((cub->dir.south + cub->dir.north
			+ cub->dir.east + cub->dir.west) > 1)
		exit_cub(cub, 1, "Error\nmore than one player position found\n");
	if ((cub->dir.south + cub->dir.north
			+ cub->dir.east + cub->dir.west) < 1)
		exit_cub(cub, 1, "Error\nno player position found\n");
	set_player_direction(cub);
}

void	check_player_format(t_cub *cub)
{
	int	i;

	i = -1;
	cub->dir.north = 0;
	cub->dir.south = 0;
	while (cub->map_1d[++i] != '\0')
	{
		if (cub->map_1d[i] == 'N')
			cub->dir.north++;
		else if (cub->map_1d[i] == 'S')
			cub->dir.south++;
	}
	check_player_format_two(cub);
}

void	check_lines(char *str, t_cub *cub)
{
	char	*temp;
	int		i;
	int		d;

	i = -1;
	d = 0;
	temp = ft_strtrim(str, " \t\n\r\f\v");
	cub->map_1d = free_null(cub->map_1d);
	str = temp;
	cub->map_1d = temp;
	while (str[++i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] == '\n' && str[i + 1] != '\0'
			&& str[i + 1] == '\n')
				d++;
	}
	if (d)
		exit_cub(cub, 1, "Error\nConsecutive new lines in map\n");
}
