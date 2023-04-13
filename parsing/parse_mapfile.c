/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:03:02 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 07:51:58 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_direction(t_cub *cub)
{
	if (cub->dir.north == 1)
		cub->dir.actual_dir = 1.5001 * PI;
	else if (cub->dir.south == 1)
		cub->dir.actual_dir = 0.5001 * PI;
	else if (cub->dir.west == 1)
		cub->dir.actual_dir = 0.001 + PI;
	else if (cub->dir.east == 1)
		cub->dir.actual_dir = 0.001;
}

void	parse_info(t_cub *cub)
{
	cub->map_1d = take_map_input(cub->fd, cub);
	cub->fd = ft_close(cub->fd);
	cub->map_1d_len = ft_strlen(cub->map_1d);
	parse_rgb(cub);
	check_for_textures(cub);
}

void	parse_map(t_cub *cub)
{
	cub->map = ft_split(cub->map_1d, '\n');
	check_positions(cub);
	check_other_format(cub);
	check_other_format_1d(cub);
	check_player_format(cub);
}

void	check_player_walls(t_cub *cub)
{
	char	*line;
	int		x;
	int 	y;

	y = -1;
	x = -1;
	get_player_index(cub, &x, &y);
	if (x == -1 || y == -1)
		exit_cub(cub, 1, "Error\nno player found in check_player_walls\n");
	line = ft_strtrim(cub->map[y], " ");
	if (x == 0 || x == (int)(ft_strlen(line) - 1))
	{
		line = free_null(line);
		exit_cub(cub, 1, "Error\nPlayer on border or not surrounded by walls\n");
	}
	if (y == 0 || y == (return_split_len(cub->map) - 1))
	{
		line = free_null(line);
		exit_cub(cub, 1, "Error\nPlayer on border or not surrounded by walls\n");
	}
	line = free_null(line);
}

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
	print_map_two(cub->map);
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
		while(line[i][j])
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
		printf("i come here\n");
		free_split(&line);
		exit_cub(cub, 1, "Error\nInvalid RGB values used\n");
	}
	if (flag == 0)
	{
		temp = rgb_to_hex(ft_atoi(line[0]), ft_atoi(line[1]), ft_atoi(line[2]), cub);
		cub->ceiling = temp;
	}
	else
	{
		temp = rgb_to_hex(ft_atoi(line[0]), ft_atoi(line[1]), ft_atoi(line[2]), cub);
		cub->floor = temp;
	}
	free_split(&line);
	if (cub->color_flag == true)
		exit_cub(cub, 1, "Error\nRGB out of bound\n");
}

int	parse(int ac, t_cub *cub, char *map_file)
{
	arg_count(ac);
	cub->fd = open(map_file, O_RDONLY);
	ft_file_ext(cub, map_file);
	parse_info(cub);
	parse_map(cub);
	validations(cub);
	return (0);
}
