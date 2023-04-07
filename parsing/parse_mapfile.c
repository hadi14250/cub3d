/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:03:02 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/07 14:56:28 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	textures(t_cub *cub, char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "NO", 3) == 0)
		cub->xpm[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0)
		cub->xpm[1] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0)
		cub->xpm[2] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0)
		cub->xpm[3] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 2) \
		&& ft_strncmp(tokens[0], "F", 2))
		return (1);
	ft_free(&tokens);
	return (0);
}

int	rgb(t_cub *cub, char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		cub->rgb[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		cub->rgb[1] = ft_strdup(tokens[1]);
	ft_free(&tokens);
	return (0);
}

int	parse_info(t_cub *cub, int fd)
{
	char	*line;

	cub->xpm = ft_calloc(sizeof(char *), 5);
	if (!cub->xpm)
		return (1);
	cub->rgb = ft_calloc(sizeof(char *), 3);
	if (!cub->rgb)
		return (1);
	while (ft_array_length(cub->xpm) != 4 || ft_array_length(cub->rgb) != 2)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) == 0)
			;
		else if (textures(cub, line) == 1 || rgb(cub, line) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		if (!line)
			break ;
	}
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
	{
		printf("file ext parse failed\n");
		exit(EXIT_FAILURE);
	}
	if (parse_info(cub, fd) == 1)
	{
		printf("invalid information, failed at parse_info function\n");
		exit(EXIT_FAILURE);
	}
	// if (parse_map(cub, fd) == 1)
	// {
	// 	printf("Error\nInvalid map\n");
	// 	exit(EXIT_FAILURE);
	// }
	cub++;
	close(fd);
	return (0);
}
