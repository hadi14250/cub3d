/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:05:39 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/10 18:17:52 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*return_str_dir(t_cub *cub)
{
	if (cub->dir.north == 1)
		return ("North");
	else if (cub->dir.south == 1)
		return ("South");
	else if (cub->dir.west == 1)
		return ("West");
	else if (cub->dir.east == 1)
		return ("East");
	return ("(null)");
}

void	print_new_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
		printf("|%s|\n", cub->map[i++]);
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
	printf("player direction is: %s\n", return_str_dir(cub));
}

/*printf("positions: no %d, ea: %d, so: %d, we: %d, map: %d,
 floor: %d, ceiling: %d\n",
	cub->no_pos, cub->ea_pos, cub->so_pos, cub->we_pos, cub->map_pos,
	cub->floor_pos, cub->ceiling_pos);*/
