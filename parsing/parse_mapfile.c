/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:03:02 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/06 17:14:29 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	textures(t_cub *game, char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "NO", 3) == 0)
		game->xpm[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0)
		game->xpm[1] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0)
		game->xpm[2] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0)
		game->xpm[3] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 2) \
		&& ft_strncmp(tokens[0], "F", 2))
		return (1);
	ft_free(&tokens);
	return (0);
}

int	rgb(t_cub *game, char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		game->rgb[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		game->rgb[1] = ft_strdup(tokens[1]);
	ft_free(&tokens);
	return (0);
}

int	parse_info(t_cub *game, int fd)
{
	char	*line;
	int		ret;

	game->xpm = ft_calloc(sizeof(char *), 5);
	if (!game->xpm)
		return (1);
	game->rgb = ft_calloc(sizeof(char *), 3);
	if (!game->rgb)
		return (1);
	while (ft_array_length(game->xpm) != 4 || ft_array_length(game->rgb) != 2)
	{
		// line = get_next_line(fd);
		ret = get_next_line(fd, &line);
		// if (ret == -1)
		// 	return (1);
		if (ft_strlen(line) == 0)
			;
		else if (textures(game, line) == 1 || rgb(game, line) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}


int	map(t_cub *game, char *line)
{
	char	**tmp;

	if (!game->map)
	{
		game->map = malloc(sizeof(char *) * 2);
		if (!game->map)
			return (1);
		game->map[0] = ft_strdup(line);
		game->map[1] = NULL;
	}
	else
	{
		tmp = ft_reallocation(game->map, ft_array_length(game->map) + 2);
		if (!tmp)
			return (1);
		game->map = tmp;
		game->map[ft_array_length(game->map)] = ft_strdup(line);
	}
	return (0);
}

int	parse_map(t_cub *game, int fd)
{
	char	*line;
	int		ret;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		if (ft_strlen(line) == 0 && !game->map)
			;
		else if (map(game, line) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}

int	parse(t_cub *game, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (ft_file_ext(fd, map_file))
	{
		printf("file ext parse failed\n");
		exit(EXIT_FAILURE);
	}
	if (parse_info(game, fd) == 1)
	{
		printf("invalid information, failed at parse_info function\n");
		exit(EXIT_FAILURE);
	}
	if (parse_map(game, fd) == 1)
	{
		printf("Error\nInvalid map\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (0);
}
