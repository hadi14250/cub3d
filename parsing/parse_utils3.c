/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:36:53 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 07:52:14 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	convert_space_to_wall(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'x' || cub->map[i][j] == ' ')
				cub->map[i][j] = '1';
			j++;
		}
		i++;
	}
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

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W'
		|| (c == ' ') || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	trim_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ')
			str[i] = '\n';
	}
}
