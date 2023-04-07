/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:03:02 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/07 21:54:49 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	{
		if (split[i])
		{
			free(split[i]);
			split[i] = NULL;
		}
	}
	free (split);
	split = NULL;
}

void	exit_cub(t_cub *cub, int code, char *msg)
{
	// int	i;

	// i = -1;
	if (cub->color_buffer)
		free(cub->color_buffer);
	if (cub->tex)
		free(cub->tex);
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
		free(cub->map_1d);
	free_split(cub->map);
	free_split(cub->xpm);
	free_split(cub->rgb);
	cub->c_rgb = free_null(cub->c_rgb);
	cub->f_rgb = free_null(cub->f_rgb);
	write(2, msg, ft_strlen(msg));
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
	cub++;
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
	if (!ft_strnstr(cub->map_1d, "NO ", cub->map_1d_len) ||
			!ft_strnstr(cub->map_1d, "SO ", cub->map_1d_len) ||
			!ft_strnstr(cub->map_1d, "WE ", cub->map_1d_len) ||
			!ft_strnstr(cub->map_1d, "EA ", cub->map_1d_len))
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
	printf("%s", cub->map_1d);
	printf("NO%s\n", cub->xpm[0]);
	printf("SO%s\n", cub->xpm[0]);
	printf("EA%s\n", cub->xpm[0]);
	printf("WE%s\n", cub->xpm[0]);
}

// void	check_cord_position(t_cub *cub)
// {
// 	int		i;
// 	char	*str;

// 	str = cub->map_1d;
// 	i = cub->map_1d_len + 1;
// 	while (--i >= 0)
// 	{
		
// 	}
// }

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

void	convert_colors(t_cub *cub, int *rgb, int flag)
{
	unsigned long	temp;

	if (flag == 0)
	{
		temp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		cub->floor = temp;
	}
	if (flag == 1)
	{
		temp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		cub->ceiling = temp;
	}
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
	{
		cub->rgb[0] = line;
		printf("line = %s\n", cub->rgb[0]);
		printf("entered in F\n");
	}
	else if (flag == 'C')
	{
		cub->rgb[1] = line;
		printf("line = %s\n", line);
		printf("entered in C\n");
	}
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

void	parse_rgb(t_cub *cub)
{
	check_floor_ceiling(cub);
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
}

int	parse_info(t_cub *cub, int fd)
{
	cub->map_1d = take_map_input(fd, cub);
	cub->map_1d_len = ft_strlen(cub->map_1d);
	cub->map = ft_split(cub->map_1d, '\n');
	parse_rgb(cub);
	// check_cord_position(cub);
	check_for_textures(cub);
	print_cub(cub);
	close(fd);
	return (0);
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

int	parse_map(t_cub *cub, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (ft_strlen(line) == 1 && !cub->map)
			;
		else if (map(cub, line) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		// if (!line)
		// 	break ;
	}
	return (0);
}

void	arg_count(int ac)
{
	if (ac != 2)
	{
		printf("[usage]: ./cub3d cubfile\n");
		exit(EXIT_FAILURE);
	}
}

int	parse(int ac, t_cub *cub, char *map_file)
{
	int	fd;

	arg_count(ac);
	fd = open(map_file, O_RDONLY);
	if (ft_file_ext(fd, map_file))
		exit_cub(cub, 1, "file ext parse failed\n");
	if (parse_info(cub, fd) == 1)
		exit_cub(cub, 1, "invalid information\n");
	// if (parse_map(cub, fd) == 1)
	// {
	// 	printf("Error\nInvalid map\n");
	// 	exit(EXIT_FAILURE);
	// }
	cub++;
	return (0);
}
