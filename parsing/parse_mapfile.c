/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:03:02 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/08 15:08:57 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	arg_count(int ac)
{
	if (ac != 2)
	{
		printf("[usage]: ./cub3d cubfile\n");
		exit(EXIT_FAILURE);
	}
}

int	ft_close(int fd)
{
	if (fd > 2)
		close(fd);
	return (-1);
}

void	*free_null(void *ptr)
{
	if (!ptr)
		return (NULL);
	free(ptr);
	return (NULL);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	if (!split)
		return ;
	while(split[++i])
		split[i] = free_null(split[i]);
	split = free_null(split);
}

void	exit_cub(t_cub *cub, int code, char *msg)
{
	// int	i;

	// i = -1;
	if (cub->color_buffer)
		cub->color_buffer = free_null(cub->color_buffer);
	if (cub->tex)
		cub->tex = free_null(cub->tex);
	// if (cub->img.img_ptr)
	// 	mlx_destroy_image(cub->mlx, cub->img.img_ptr);
	// while(++i < 4)
	// {
	// 	// if (cub->img2[i].img_ptr)
	// 	// 	mlx_destroy_image(cub->mlx, cub->img2[i].img_ptr);
	// }
	// if (cub->win)
	// 	mlx_destroy_window(cub->mlx, cub->win);
	if (cub->map_1d)
		cub->map_1d = free_null(cub->map_1d);
	free_split(cub->map);
	free_split(cub->xpm);
	free_split(cub->rgb);
	cub->c_rgb = free_null(cub->c_rgb);
	cub->f_rgb = free_null(cub->f_rgb);
	cub->fd = ft_close(cub->fd);
	printf("%s", msg);
	exit (code);
}

void	null_params(char **tmp, char **total, char **line)
{
	*tmp = NULL;
	*total = NULL;
	*line = NULL;
}

void	free_params(char **line, char **tmp, char **input)
{
	*line = free_null(*line);
	*tmp = free_null(*tmp);
	*input = free_null(*input);
}

char	*take_map_input(int fd, t_cub *cub)
{
	t_buff h;

	null_params(&h.tmp, &h.total, &h.line);
	while(1)
	{
		h.i = get_next_line(fd);
		if (!h.i)
			break ;
		h.tmp = h.line;
		h.line = gl_strjoin(h.i, "\n");
		h.tmp = free_null(h.tmp);
		h.tmp = h.total;
		h.total = gl_strjoin(h.total, h.line);
		free_params(&h.line, &h.tmp, &h.i);
	}
	if (!h.total)
		exit_cub(cub, 1, "Error\ncan't have empty map\n");
	return (h.total);
}

// int	parse_xpm(t_cub *cub, int fd)
// {
// 	char	*line;

// 	cub->xpm = ft_calloc(sizeof(char *), 5);
// 	if (!cub->xpm)
// 		return (1);
// 	cub->rgb = ft_calloc(sizeof(char *), 3);
// 	if (!cub->rgb)
// 		return (1);
// 	while (ft_array_length(cub->xpm) != 4 || ft_array_length(cub->rgb) != 2)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		if (ft_strlen(line) == 0)
// 		{
// 			if (line[0])
// 				free(line);
// 		}
// 		else if (textures(cub, line) == 1 || rgb(cub, line) == 1)
// 		{
// 			free(line);
// 			line = NULL;
// 			return (1);
// 		}
// 		free(line);
// 		line = NULL;
// 	}
// 	if (line)
// 		free(line);
// 	return (0);
// }

size_t	ft_tex_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_tex_dup(const char *s1)
{
	int		i;
	int		d;
	char	*tmp;
	int		size;

	i = 0;
	d = 0;
	size = ft_tex_len((char *)s1);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		tmp[d] = s1[i];
		i++;
		d++;
	}
	tmp[d] = '\0';
	return (tmp);
}

void	check_for_textures(t_cub *cub)
{
	cub->xpm = ft_calloc(5, sizeof(char *));
	if (!cub->xpm)
		exit_cub(cub, 1, "memory allocation fail\n");
	if (!ft_strnstr(cub->map_1d, "NO", cub->map_1d_len) ||
			!ft_strnstr(cub->map_1d, "SO", cub->map_1d_len) ||
			!ft_strnstr(cub->map_1d, "WE", cub->map_1d_len) ||
			!ft_strnstr(cub->map_1d, "EA", cub->map_1d_len))
		exit_cub(cub, 1, "texture not found\n");
	if(!ft_strnstr(cub->map_1d, "./game_textures/NO.xpm", cub->map_1d_len))
		exit_cub(cub, 1, "NO texture file not found\n");
	else
		cub->xpm[0] = ft_strdup("./game_textures/NO.xpm");
	if(!ft_strnstr(cub->map_1d, "./game_textures/SO.xpm", cub->map_1d_len))
		exit_cub(cub, 1, "SO texture file not found\n");
	else
		cub->xpm[1] = ft_strdup("./game_textures/SO.xpm");
	if(!ft_strnstr(cub->map_1d, "./game_textures/WE.xpm", cub->map_1d_len))
		exit_cub(cub, 1, "WE texture file not found\n");
	else
		cub->xpm[2] = ft_strdup("./game_textures/WE.xpm");
	if(!ft_strnstr(cub->map_1d, "./game_textures/EA.xpm", cub->map_1d_len))
		exit_cub(cub, 1, "EA texture file not found\n");
	else
		cub->xpm[3] = ft_strdup("./game_textures/EA.xpm");
	if (!cub->xpm[0] || !cub->xpm[1] || !cub->xpm[2] || !cub->xpm[3])
		exit_cub(cub, 1, "memory allocation fail\n");
}

void	print_cub(t_cub *cub)
{
	printf("1D MAP: -->%s<--\n", cub->map_1d);
	printf("NO: -->%s<--\n", cub->xpm[0]);
	printf("SO: -->%s<--\n", cub->xpm[1]);
	printf("EA: -->%s<--\n", cub->xpm[2]);
	printf("WE: -->%s<--\n", cub->xpm[3]);
	printf("floor color: -->%ld<--\n", cub->floor);
	printf("ceiling color: -->%ld<--\n", cub->ceiling);
	printf("positions: no %d, ea: %d, so: %d, we: %d, map: %d, floor: %d, ceiling: %d\n",
	cub->no_pos, cub->ea_pos, cub->so_pos, cub->we_pos, cub->map_pos,
	cub->floor_pos, cub->ceiling_pos);
	printf("max is: %d and it is --->%s<---\n", cub->max, cub->map[cub->max]);
}

void	trim_comma(char *str)
{
	int	i;

	i = -1;
	while(str[++i] != '\0' && str[i] != '\n')
	{
		if (str[i] == ',')
			str[i] = ' ';
	}
}

void	convert_colors(t_cub *cub, char *rgb, int flag)
{
	unsigned long	temp;
	char			**line;

	cub->color_flag = false;
	line = ft_split(rgb, ' ');
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
	free_split(line);
	if (cub->color_flag == true)
		exit_cub(cub, 1, "rgb out of bound\n");
}

int	rgb(t_cub *cub, char *line, char flag)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (ft_array_length(tokens) != 3)
	{
		free_split(tokens);
		exit_cub(cub, 1, "rgb validation failed\n");
	}
	if (flag == 'F')
		cub->rgb[0] = ft_strdup(line);
	else if (flag == 'C')
		cub->rgb[1] = ft_strdup(line);
	free_split(tokens);
	return (0);
}

void	check_floor_ceiling(t_cub *cub)
{
	char	*str;
	int		i;
	int		c;
	int		f;

	c = 0;
	f = 0;
	i = -1;
	str = cub->map_1d;
	while (str[++i] != '\0')
	{
		if (str[i] == 'C')
			c++;
		if (str[i] == 'F')
			f++;
	}
	if (!c || !f || c > 1 || f > 1)
		exit_cub(cub, 1, "invalid rgb format");
}

void	check_north_south(t_cub *cub)
{
	char	*north;
	char	*south;

	north = ft_strnstr(cub->map_1d, "NO", cub->map_1d_len);
	if (!north)
		exit_cub(cub, 1, "Error\nNO not found");
	north += 2;
	north = ft_strnstr(north, "NO", cub->map_1d_len);
	if (!north)
		exit_cub(cub, 1, "Error\n NO invalid\n");
	north += 2;
	north = ft_strnstr(north, "NO", cub->map_1d_len);
	if (north)
		exit_cub(cub, 1, "Error\nmore than one NO texture found\n");
	south = ft_strnstr(cub->map_1d, "SO", cub->map_1d_len);
	if (!south)
		exit_cub(cub, 1, "Error\nSO not found");
	south += 2;
	south = ft_strnstr(south, "SO", cub->map_1d_len);
	if (!south)
		exit_cub(cub, 1, "Error\n SO invalid\n");
	south += 2;
	south = ft_strnstr(south, "SO", cub->map_1d_len);
	if (south)
		exit_cub(cub, 1, "Error\nmore than one SO texture found\n");
}

void	east_west(t_cub *cub)
{
	char	*east;
	char	*west;

	east = ft_strnstr(cub->map_1d, "EA", cub->map_1d_len);
	if (!east)
		exit_cub(cub, 1, "Error\nEA not found");
	east += 2;
	east = ft_strnstr(east, "EA", cub->map_1d_len);
	if (!east)
		exit_cub(cub, 1, "Error\n EA invalid\n");
	east += 2;
	east = ft_strnstr(east, "EA", cub->map_1d_len);
	if (east)
		exit_cub(cub, 1, "Error\nmore than one EA texture found\n");
	west = ft_strnstr(cub->map_1d, "WE", cub->map_1d_len);
	if (!west)
		exit_cub(cub, 1, "Error\nWE not found");
	west += 2;
	west = ft_strnstr(west, "WE", cub->map_1d_len);
	if (!west)
		exit_cub(cub, 1, "Error\n WE invalid\n");
	west += 2;
	west = ft_strnstr(west, "WE", cub->map_1d_len);
	if (west)
		exit_cub(cub, 1, "Error\nmore than one WE texture found\n");
}

void	parse_rgb(t_cub *cub)
{
	check_floor_ceiling(cub);
	check_north_south(cub);
	east_west(cub);
	cub->rgb = ft_calloc(5, sizeof(char *));
	cub->c_rgb = ft_strnstr(cub->map_1d, "C", cub->map_1d_len);
	cub->c_rgb = ft_tex_dup(cub->c_rgb);
	trim_comma(cub->c_rgb);
	cub->f_rgb = ft_strnstr(cub->map_1d, "F", cub->map_1d_len);
	cub->f_rgb = ft_tex_dup(cub->f_rgb);
	trim_comma(cub->f_rgb);
	rgb(cub, ft_strnstr(cub->c_rgb, "C", ft_strlen(cub->c_rgb)) + 1, 'C');
	rgb(cub, ft_strnstr(cub->f_rgb, "F", ft_strlen(cub->f_rgb)) + 1, 'F');
	cub->c_rgb = free_null(cub->c_rgb);
	cub->f_rgb = free_null(cub->f_rgb);
	convert_colors(cub, cub->rgb[1], 0);;
	convert_colors(cub, cub->rgb[0], 1);
}

void	parse_info(t_cub *cub)
{
	cub->map_1d = take_map_input(cub->fd, cub);
	cub->fd = ft_close(cub->fd);
	cub->map_1d_len = ft_strlen(cub->map_1d);
	parse_rgb(cub);
	check_for_textures(cub);
}

int	map(t_cub *cub, char *line)
{
	char	**tmp;

	if (!cub->map)
	{
		cub->map = malloc(sizeof(char *) * 2);
		if (!cub->map)
			return (1);
		cub->map[0] = ft_strdup(line);
		cub->map[1] = NULL;
	}
	else
	{
		tmp = ft_reallocation(cub->map, ft_array_length(cub->map) + 2);
		if (!tmp)
			return (1);
		cub->map = tmp;
		cub->map[ft_array_length(cub->map)] = ft_strdup(line);
	}
	return (0);
}

int	return_len(char **split)
{
	int	i;
	int	d;

	d = 0;
	i = -1;
	while(split[++i] != NULL)
		d += ft_strlen(split[i]) + 1;
	return (d);
}

void	print_map_two(char **split)
{
	int	i;

	if (!split)
	{
		return ;
	}
	i = -1;
	while (split[++i])
		printf("->%s<-\n", split[i]);
	printf("\n");
}

int	return_split_len(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != NULL)
		;
	return (i);
}

void	realloc_map(char **half_map, t_cub *cub)
{
	int		new_len;
	int		bmap_len;
	int		i;
	char	*new;
	int		d;

	d = -1;
	new_len = return_len(half_map);
	bmap_len = cub->map_1d_len - new_len;
	i = bmap_len - 1;
	new = ft_calloc((cub->map_1d_len - bmap_len) + 1, sizeof(char));
	while(cub->map_1d[++i] != '\0')
		new[++d] = cub->map_1d[i];
	new[d] = '\0';
	cub->map_1d = free_null(cub->map_1d);
	cub->map_1d = new;
	cub->map_1d_len = ft_strlen(new);
}

void	check_map_pos(t_cub *cub, char **half_map)
{
	int	i;

	i = cub->max - 1;
	if (i <= 1)
		exit_cub(cub, 1, "Invalid map\n");
	if (!half_map || !half_map[0])
		exit_cub(cub, 1, "Error\nunorganized map\n");
	while (i >= 0)
	{
		if (ft_strnstr(cub->map[i], "111", ft_strlen(cub->map[i])))
			{
				if (!ft_strnstr(cub->map[i], cub->map[cub->floor_pos],
					ft_strlen(cub->map[i])) &&
					!ft_strnstr(cub->map[i], cub->map[cub->ceiling_pos],
					ft_strlen(cub->map[i])))
					exit_cub(cub, 1, "Error\ninvalid map\n");
			}
			i--;
	}
	realloc_map(half_map, cub);
}

void	check_positions(t_cub *cub)
{
	int		i;
	char	**split;
	int		d;

	d = 0;
	cub->max = 0;
	split = cub->map;
	i=  -1;
	while(split[++i] != NULL)
	{
		if (ft_strnstr(split[i], "NO", ft_strlen(split[i])))
		{
			cub->no_pos = i;
			if (i > cub->max)
				cub->max = i;
			d++;
		}
		if (ft_strnstr(split[i], "SO", ft_strlen(split[i])))
		{
			cub->so_pos = i;
			if (i > cub->max)
				cub->max = i;
			d++;
		}
		if (ft_strnstr(split[i], "WE", ft_strlen(split[i])))
		{
			cub->we_pos = i;
			if (i > cub->max)
				cub->max = i;
			d++;
		}
		if (ft_strnstr(split[i], "EA", ft_strlen(split[i])))
		{
			cub->ea_pos = i;
			if (i > cub->max)
				cub->max = i;
			d++;
		}
		if (ft_strnstr(split[i], "F", ft_strlen(split[i])))
		{
			cub->floor_pos = i;
			if (i > cub->max)
				cub->max = i;
			d++;
		}
		if (ft_strnstr(split[i], "C", ft_strlen(split[i])))
		{
			cub->ceiling_pos = i;
			if (i > cub->max)
				cub->max = i;
			d++;
		}
	}
	check_map_pos(cub, &cub->map[cub->max + 1]);
}

void	trim_spaces(char *str)
{
	int	i;

	i = -1;
	while(str[++i] != '\0')
	{
		if (str[i] == ' ')
			str[i] = '\n';
	}
}

int	check_spaces(char *str)
{
	int	i;
	int	d;

	i = -1;
	d = 0;
	while(str[++i] != '\0')
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
		if (i != cub->no_pos && i != cub->ea_pos &&
			i != cub->so_pos && i != cub->we_pos &&
			i != cub->floor_pos && i != cub->ceiling_pos)
			{
				if (check_spaces(cub->map[i]))
				{
					printf("Error: position %d: invalid format: -->%s<--\n",
						i, cub->map[i]);
					exit_cub(cub, 1, "");
				}
			}
	}
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' ||
		c == 'S' || c == 'E' || c == 'W'
		|| (c == ' ') || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	check_other_format_1d(t_cub *cub)
{
	int		i;
	int		d;
	int		j;
	int		r;

	r = 0;
	i = -1;
	d = 0;
	j = 0;
	while(cub->map_1d[++i] != '\0')
	{
		if (is_valid_char(cub->map_1d[i]))
			d++;
		else
		{
			if (j == 0)
				printf("Error\ninvalid character(s): ");
			printf("->%c<- in column %d, ", cub->map_1d[i], r + 1);
			j++;
		}
		if (cub->map_1d[i] == '\n')
			r++;
	}
	if (d != i)
		exit_cub(cub, 1, "\n");
}

void	parse_map(t_cub *cub)
{
	cub->map = ft_split(cub->map_1d, '\n');
	check_positions(cub);
	check_other_format(cub);
	check_other_format_1d(cub);
}

int	parse(int ac, t_cub *cub, char *map_file)
{
	arg_count(ac);
	cub->fd = open(map_file, O_RDONLY);
	ft_file_ext(cub, map_file);
	parse_info(cub);
	parse_map(cub);
	return (0);
}
