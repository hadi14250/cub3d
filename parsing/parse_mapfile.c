/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:03:02 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 06:29:48 by bsaeed           ###   ########.fr       */
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

void	free_split(char ***split)
{
	int		i;
	char	**to_free;

	to_free = *split;
	i = -1;
	if (!to_free)
		return ;
	while(to_free[++i])
		to_free[i] = free_null(to_free[i]);
	*split = free_null(to_free);
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
	free_split(&cub->map);
	free_split(&cub->xpm);
	free_rgbs(cub);
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

void	print_map_two(char **split)
{
	int	i;

	if (!split)
	{
		return ;
	}
	i = -1;
	while (split[++i])
		printf("--->%s<---\n", split[i]);
	printf("\n");
}

void	print_cub(t_cub *cub)
{
	printf("1D MAP: -->\n%s<--\n", cub->map_1d);
	printf("2D MAP:\n");
	print_map_two(cub->map);
	printf("NO: -->%s<--\n", cub->xpm[0]);
	printf("SO: -->%s<--\n", cub->xpm[1]);
	printf("EA: -->%s<--\n", cub->xpm[2]);
	printf("WE: -->%s<--\n", cub->xpm[3]);
	printf("floor color: -->%ld<--\n", cub->floor);
	printf("ceiling color: -->%ld<--\n", cub->ceiling);
	printf("positions: no %d, ea: %d, so: %d, we: %d, map: %d, floor: %d, ceiling: %d\n",
	cub->no_pos, cub->ea_pos, cub->so_pos, cub->we_pos, cub->map_pos,
	cub->floor_pos, cub->ceiling_pos);
	printf("player direction is: %f\n", cub->dir.actual_dir);
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

int	rgb(t_cub *cub, char *line, char flag)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (ft_array_length(tokens) != 3)
	{
		free_split(&tokens);
		exit_cub(cub, 1, "Error\nRGB validation failed\n");
	}
	if (flag == 'F')
		cub->rgb[0] = ft_strdup(line);
	else if (flag == 'C')
		cub->rgb[1] = ft_strdup(line);
	free_split(&tokens);
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
		exit_cub(cub, 1, "Error\ninvalid rgb format\n");
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
	convert_colors(cub, cub->rgb[1], 0);
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

int	return_split_len(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != NULL)
		;
	return (i);
}

void	trim_map_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = '0';
	}
}

void	check_lines(char *str, t_cub *cub);

int	return_double_len(char **split)
{
	int	i;
	int	d;

	d = 0;
	i = 0;
	if (!split || !split[0])
		return (0);
	while (split[i] != NULL)
	{
		d += (ft_strlen(split[i]));
		i++;
	}
	return (d - i);
}

// void	realloc_map(t_cub *cub)
// {
// 	char	*temp;
// 	int		len;
// 	int		arr_len;

// 	arr_len = return_double_len(&cub->map[cub->max + 1]);
// 	check_lines(cub->map_1d + arr_len, cub);
// 	len = return_split_len(&cub->map[cub->max]);
// 	temp  = ft_strsjoin(len, &cub->map[cub->max], "\n");
// 	cub->map_1d = free_null(cub->map_1d);
// 	cub->map_1d = temp;
// 	// trim_map_spaces(cub->map_1d);
// 	printf("mapmap map map is ------------------>\n%s<--------------\n", cub->map_1d);
// }

int	check_next_line(t_cub *cub, char *str, int len)
{
	int	num[2];

	num[1] = 0;
	while(len >= 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	num[0] = len;
	if (len >= 0 && str[len] == '\n')
	{
		while (len >= 0 && (str[len] == ' ' || str[len] == '\t' ||
			str[len] == '\n' || str[len] == '\r' || str[len] == '\f' ||
			str[len] == '\v'))
				len--;
		if (len >= 0 && (str[len] == '1' || str[len] == '0' ||
			str[len] == ' ' || str[len] == 'E' || str[len] == 'S' ||
			str[len] == 'W' || str[len] == 'N'))
			{
				num[1] = 1;
				while (len >= 0 && str[len] != '\n')
					if (str[len--] == 'F' || str[len] == 'C')
						num[1] = 0;
				if (num[1] != 0)
					exit_cub(cub, 1, "Error\nconesecutive new lines in map\n");
			}
	}
	return (num[0]);
}

void	check_for_lines(t_cub *cub)
{
	char	*str;
	int		len;

	len = ft_strlen(cub->map_1d) - 1;
	str = cub->map_1d; //  \t\n\r\f\v
	while (len >= 0 && (str[len] == ' ' || str[len] == '\t' ||
		str[len] == '\n' || str[len] == '\r' || str[len] == '\f' ||
		str[len] == '\v'))
			len--;
	while (len >= 0 && (str[len] == '1' || str[len] == '0' ||
		str[len] == ' ' || str[len] == 'E' || str[len] == 'S' ||
		str[len] == 'W' || str[len] == 'N' || str[len] == '\n' ||
		str[len] == '\t'))
	{
		if (str[len] == '\n')
			len = check_next_line(cub, str, len - 1);
		len--;
	}
}

char	*ft_maptrim(char const *s1, char const *set)
{
	int		i;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen((char *)s1);
	while (*s1 && ft_strrchr(set, s1[i]))
		i--;
	res = ft_substr(s1, 0, i + 1);
	return (res);
}

void	realloc_map(t_cub *cub)
{
	char	*temp;
	int		len;

	check_for_lines(cub);
	len = return_split_len(&cub->map[cub->max]);
	temp  = ft_strsjoin(len, &cub->map[cub->max], "\n");
	cub->map_1d = free_null(cub->map_1d);
	cub->map_1d = temp;
	temp = ft_maptrim(cub->map_1d, "\n\r\f\v");
	cub->map_1d = free_null(cub->map_1d);
	cub->map_1d = temp;
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
	realloc_map(cub);
}

void	check_positions(t_cub *cub)
{
	int		i;
	char	**split;

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
		}
		if (ft_strnstr(split[i], "SO", ft_strlen(split[i])))
		{
			cub->so_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
		if (ft_strnstr(split[i], "WE", ft_strlen(split[i])))
		{
			cub->we_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
		if (ft_strnstr(split[i], "EA", ft_strlen(split[i])))
		{
			cub->ea_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
		if (ft_strnstr(split[i], "F", ft_strlen(split[i])))
		{
			cub->floor_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
		if (ft_strnstr(split[i], "C", ft_strlen(split[i])))
		{
			cub->ceiling_pos = i;
			if (i > cub->max)
				cub->max = i;
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
					printf("Error\nposition %d: invalid format: -->%s<--\n",
						i + 1, cub->map[i]);
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
	int	i;
	int	d;

	i = -1;
	d = 0;
	temp = ft_strtrim(str, " \t\n\r\f\v");
	cub->map_1d = free_null(cub->map_1d);
	str = temp;
	cub->map_1d = temp;
	while (str[++i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' ||
				str[i] == '\t'))
					i++;
		if (str[i] == '\n' && str[i + 1] != '\0'
			&& str[i + 1] == '\n')
				d++;
	}
	if (d)
		exit_cub(cub, 1, "Error\nconesuctive new lines in map\n");
}

void	convert_spaces(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map_1d[i])
	{
		if (cub->map_1d[i] == '\t' || cub->map_1d[i] == '\r'
			|| cub->map_1d[i] == '\v' || cub->map_1d[i] == '\f')
			cub->map_1d[i] = ' ';
		i++;
	}
}

void	convert_space_to_wall(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map_1d[i])
	{
		if (cub->map_1d[i] == ' ')
			cub->map_1d[i] = '1';
		i++;
	}
}

void	print_new_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
		printf("|%s|\n", cub->map[i++]);
}

void	parse_map(t_cub *cub)
{
	cub->map = ft_split(cub->map_1d, '\n');
	check_positions(cub);
	check_other_format(cub);
	check_other_format_1d(cub);
	check_player_format(cub);
}

int	get_longest_line(char **split)
{
	int	i;
	int	len;
	int	longest;

	i = 0;
	len = -1;
	longest = -1;
	while (split[i])
	{
		len = ft_strlen(split[i]);
		if (len > longest)
			longest = len;
		i++;
	}
	return (longest);
}

void	*callocer(int size, int block, t_cub *cub)
{
	void	*ptr;

	ptr = ft_calloc(block, size);
	if (!ptr)
		exit_cub(cub, 1, "Error\nmemory allocation failed");
	return(ptr);
}

int	check_up(t_cub *cub, int i, int j)
{
	int	up;

	up = i;
	if (i == 0)
		exit_cub(cub, 1, "'0' found at the top of the map\n");
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
		exit_cub(cub, 1, "'0' found at the top of the map\n");
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
		exit_cub(cub, 1, "'0' found at the top of the map\n");
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
		exit_cub(cub, 1, "'0' found at the top of the map\n");
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

void	*allocate_new_map(t_cub *cub)
{
	int		longest;
	int		height;
	char	**new;
	int		i;

	i = 0;
	longest = get_longest_line(cub->map);
	height = return_split_len(cub->map);
	new = callocer(height + 1, sizeof(char *), cub);
	while (i < height)
	{
		new[i] = callocer(longest + 1, sizeof(char), cub);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	memset_map(t_cub *cub, char **tmp_map, char flag)
{
	int	i;
	int	longest;

	i = 0;
	longest = get_longest_line(cub->map);
	printf("longest = %d\n", longest);
	while (cub->map[i])
	{
		ft_memset(tmp_map[i], flag, longest);
		tmp_map[i][longest] = '\0';
		i++;
	}
}

void	hadis_rectangle_map(t_cub *cub, char **tmp_map)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			tmp_map[i][j] = cub->map[i][j];
			j++;
		}
		i++;
	}
	free_split(&cub->map);
	cub->map = tmp_map;
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

void	check_player_walls(t_cub *cub)
{
	char	*line;
	int		x;
	int		y;

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

	/*SPLITTING MAP AGAIN FOR '0' BORDER CHECKS TO AVOID INVALID READ*/
	temp = allocate_new_map(cub);
	memset_map(cub, temp, 'x');
	hadis_rectangle_map(cub, temp);
	check_borders(cub);
	
	free_split(&cub->map);
	convert_space_to_wall(cub);
	cub->map = ft_split(cub->map_1d, '\n');
	temp = allocate_new_map(cub);
	memset_map(cub, temp, '1');
	hadis_rectangle_map(cub, temp);
	print_map_two(cub->map);
}

int	parse(int ac, t_cub *cub, char *map_file)
{
	arg_count(ac);
	cub->fd = open(map_file, O_RDONLY);
	ft_file_ext(cub, map_file);
	parse_info(cub);
	parse_map(cub);

	/* MORE PARSING*/

	// validate_map(cub);
	validations(cub);

	return (0);
}
