/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:52:17 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/04 15:08:50 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_characters(t_cub *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_strchr(" 10NSEW", game->map[i][j]))
				return (0);
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' \
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				//init_vectors(j, i);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	is_closed(t_cub *game, int i, int j)
{
	if (game->map[i][j] == '0' \
		|| (game->map[i][j] != '1' && game->map[i][j] != ' '))
	{
		if (i == 0 || !game->map[i + 1] || j == 0 || !game->map[i][j + 1])
		{
			printf("failed here\n");
			return (1);
		}
		if (game->map[i - 1] && game->map[i - 1][j]
			&& game->map[i - 1][j] == ' ')
			{
			printf("failed here1\n");
			return (1);
		}
		if (game->map[i + 1] && game->map[i + 1][j]
			&& game->map[i + 1][j] == ' ')
			{
			printf("failed here2\n");
			return (1);
		}
		if (game->map[i] && game->map[i][j - 1]
			&& game->map[i][j - 1] == ' ')
			{
			printf("failed here3\n");
			return (1);
		}
		if (game->map[i] && game->map[i][j + 1]
			&& game->map[i][j + 1] == ' ')
			{
			printf("failed here4\n");
			return (1);
		}
	}
	return (0);
}

int	is_end(t_cub *game, int index)
{
	int	i;

	i = index;
	i++;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) > 0)
			return (1);
		i++;
	}
	game->map[i] = NULL;
	return (0);
}

int	validate_map(t_cub *game)
{
	int	i;
	int	j;

	if (ft_array_length(game->map) < 3 || check_characters(game) != 1)
	{
		printf("a11\n");
		return (1);
	}
	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) == 0)
		{
			if (is_end(game, i) == 1)
			{
				printf("a2\n");
				return (1);
			}
			break ;
		}
		j = 0;
		while (game->map[i][j])
		{
			if (is_closed(game, i, j) == 1)
			{
				printf("a3\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
