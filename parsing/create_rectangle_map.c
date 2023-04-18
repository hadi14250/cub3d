/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rectangle_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:31:49 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 08:56:16 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
