/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:07:14 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/05 20:51:42 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_textures(t_cub *game, int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->img2[i].height)
	{
		x = -1;
		while (++x < game->img2[i].width)
		{
			game->texture[i][game->img2[i].height * y + x] = \
				(game->img2[i].address[game->img2[i].height * y + x]);
		}
	}
}

// char	*trimmer(char *texture_path)
// {
// 	char	*res;

// 	res = ft_strtrim(texture_path, "\n");
// 	free(texture_path);
// 	return (res);
// }

int	init_textures(t_cub *game)
{
	int		i;
	int		*address;

	i = 0;
	while (i < 4)
	{
		game->img2[i].img_ptr = mlx_xpm_file_to_image(game->mlx, game->xpm[i], \
			&(game->img2[i].width), &(game->img2[i].height));
		if (!game->img2[i].img_ptr)
		{
			printf("failing here, i = %d\n", i);
			return (1);
		}
		address = (int *) mlx_get_data_addr(game->img2[i].img_ptr, &game->img2[i].bits_per_pixel,
			&game->img2[i].line_length, &game->img2[i].endian);
		game->img2[i].address = address;
		if (!game->img2[i].address)
			return (1);
		fill_textures(game, i);
		// mlx_destroy_image(game->mlx, game->img2[i].img_ptr);
		i++;
	}
	return (0);
}

