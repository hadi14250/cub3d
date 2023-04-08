/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:52:17 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/07 15:39:41 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_characters(t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (!ft_strchr(" 10NSEW", cub->map[i][j]))
				return (0);
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' \
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
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

int	is_closed(t_cub *cub, int i, int j)
{
	if (cub->map[i][j] == '0' \
		|| (cub->map[i][j] != '1' && cub->map[i][j] != ' '))
	{
		if (i == 0 || !cub->map[i + 1] || j == 0 || !cub->map[i][j + 1])
		{
			printf("failed here\n");
			return (1);
		}
		if (cub->map[i - 1] && cub->map[i - 1][j]
			&& cub->map[i - 1][j] == ' ')
			{
			printf("failed here1\n");
			return (1);
		}
		if (cub->map[i + 1] && cub->map[i + 1][j]
			&& cub->map[i + 1][j] == ' ')
			{
			printf("failed here2\n");
			return (1);
		}
		if (cub->map[i] && cub->map[i][j - 1]
			&& cub->map[i][j - 1] == ' ')
			{
			printf("failed here3\n");
			return (1);
		}
		if (cub->map[i] && cub->map[i][j + 1]
			&& cub->map[i][j + 1] == ' ')
			{
			printf("failed here4\n");
			return (1);
		}
	}
	return (0);
}

int	is_end(t_cub *cub, int index)
{
	int	i;

	i = index;
	i++;
	while (cub->map[i])
	{
		if (ft_strlen(cub->map[i]) > 0)
			return (1);
		i++;
	}
	cub->map[i] = NULL;
	return (0);
}

int	validate_map(t_cub *cub)
{
	// int	i;
	// int	j;

	// if (ft_array_length(cub->map) < 3 || check_characters(cub) != 1)
	// {
	// 	printf("a1\n");
	// 	return (1);
	// }
	// i = 0;
	// while (cub->map[i])
	// {
	// 	if (ft_strlen(cub->map[i]) == 0)
	// 	{
	// 		if (is_end(cub, i) == 1)
	// 		{
	// 			printf("a2\n");
	// 			return (1);
	// 		}
	// 		break ;
	// 	}
	// 	j = 0;
	// 	while (cub->map[i][j])
	// 	{
	// 		if (is_closed(cub, i, j) == 1)
	// 		{
	// 			printf("a3\n");
	// 			return (1);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	(void)cub;
	return (0);
}
