/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:23:46 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 08:14:11 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		exit_cub(cub, 1, "Error\nInvalid rgb format");
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

void	check_tex_alloc(t_cub *cub)
{
	cub->xpm = ft_calloc(5, sizeof(char *));
	if (!cub->xpm)
		exit_cub(cub, 1, "Error\nmemory allocation fail\n");
	if (!ft_strnstr(cub->map_1d, "NO", cub->map_1d_len)
		|| !ft_strnstr(cub->map_1d, "SO", cub->map_1d_len)
		|| !ft_strnstr(cub->map_1d, "WE", cub->map_1d_len)
		|| !ft_strnstr(cub->map_1d, "EA", cub->map_1d_len))
		exit_cub(cub, 1, "Error\ntexture not found\n");
}

void	check_for_textures(t_cub *cub)
{
	check_tex_alloc(cub);
	if (!ft_strnstr(cub->map_1d, "./game_textures/NO.xpm", cub->map_1d_len))
		exit_cub(cub, 1, "Error\nNO texture file not found\n");
	else
		cub->xpm[0] = ft_strdup("./game_textures/NO.xpm");
	if (!ft_strnstr(cub->map_1d, "./game_textures/SO.xpm", cub->map_1d_len))
		exit_cub(cub, 1, "Error\nSO texture file not found\n");
	else
		cub->xpm[1] = ft_strdup("./game_textures/SO.xpm");
	if (!ft_strnstr(cub->map_1d, "./game_textures/WE.xpm", cub->map_1d_len))
		exit_cub(cub, 1, "Error\nWE texture file not found\n");
	else
		cub->xpm[2] = ft_strdup("./game_textures/WE.xpm");
	if (!ft_strnstr(cub->map_1d, "./game_textures/EA.xpm", cub->map_1d_len))
		exit_cub(cub, 1, "Error\nEA texture file not found\n");
	else
		cub->xpm[3] = ft_strdup("./game_textures/EA.xpm");
	if (!cub->xpm[0] || !cub->xpm[1] || !cub->xpm[2] || !cub->xpm[3])
		exit_cub(cub, 1, "Error\nmemory allocation fail\n");
}
