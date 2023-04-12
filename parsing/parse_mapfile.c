/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:03:02 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/12 20:33:02 by bsaeed           ###   ########.fr       */
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

void	check_player_on_border(t_cub *cub)
{
	int height;
	int width;
	int i;

	i = 0;
	width = get_longest_line(cub->map) - 1;
	height = return_split_len(cub->map);
	while (i < height)
	{
		if (cub->map[i][width] == 'N' || cub->map[i][0] == 'N'
			|| cub->map[i][width] == 'E' || cub->map[i][0] == 'E'
			|| cub->map[i][width] == 'S' || cub->map[i][0] == 'S'
			|| cub->map[i][width] == 'W' || cub->map[i][0] == 'W')
			exit_cub(cub, 1, "Error\nPlayer position on border\n");
		i++;
	}
}

void	validations(t_cub *cub)
{
	char	**temp;

	convert_spaces(cub);
	free_split(&cub->map);
	cub->map = ft_split(cub->map_1d, '\n');
	check_borders(cub);
	free_split(&cub->map);
	convert_space_to_wall(cub);
	cub->map = ft_split(cub->map_1d, '\n');
	temp = allocate_new_map(cub);
	memset_map(cub, temp);
	hadis_rectangle_map(cub, temp);
	check_player_on_border(cub);
	print_map_two(cub->map);
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
