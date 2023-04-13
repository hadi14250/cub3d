/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:05:25 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/13 09:10:28 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_texes(t_cub *cub)
{	
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (cub->img2[i].img_ptr)
			mlx_destroy_image(cub->mlx, cub->img2[i].img_ptr);
	}
}

void	validations(t_cub *cub)
{
	char	**temp;

	convert_spaces(cub);
	free_split(&cub->map);
	cub->map = ft_split(cub->map_1d, '\n');
	check_player_walls(cub);
	check_map_lines(cub);
	check_for_walls(cub);
	temp = allocate_new_map(cub);
	memset_map(cub, temp, 'x');
	hadis_rectangle_map(cub, temp);
	check_borders(cub);
	convert_space_to_wall(cub);
}

void	free_rgbs(t_cub *cub)
{
	if (cub->rgb)
	{
		if (cub->rgb[0])
			free_null(cub->rgb[0]);
		if (cub->rgb[1])
			free_null(cub->rgb[1]);
	}
	free(cub->rgb);
}

int	check_rgbs(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (ft_isdigit(line[i][j]) == 0)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	convert_colors(t_cub *cub, char *rgb, int flag)
{
	unsigned long	temp;
	char			**line;

	cub->color_flag = false;
	line = ft_split(rgb, ' ');
	if (check_rgbs(line) == EXIT_FAILURE)
	{
		free_split(&line);
		exit_cub(cub, 1, "Error\nInvalid RGB values used\n");
	}
	if (flag == 0)
	{
		temp = rgb_to_hex(ft_atoi(line[0]), ft_atoi(line[1]),
				ft_atoi(line[2]), cub);
		cub->ceiling = temp;
	}
	else
	{
		temp = rgb_to_hex(ft_atoi(line[0]), ft_atoi(line[1]),
				ft_atoi(line[2]), cub);
		cub->floor = temp;
	}
	free_split(&line);
	if (cub->color_flag == true)
		exit_cub(cub, 1, "Error\nRGB out of bound\n");
}
