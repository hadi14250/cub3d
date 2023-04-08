/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:07:14 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/08 04:14:34 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_textures(t_cub *cub, int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->img2[i].height)
	{
		x = -1;
		while (++x < cub->img2[i].width)
		{
			cub->texture[i][cub->img2[i].height * y + x] = \
				(cub->img2[i].address[cub->img2[i].height * y + x]);
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

int	init_textures(t_cub *cub)
{
	int		i;
	int		*address;

	i = 0;
	while (i < 4)
	{
		cub->img2[i].img_ptr = mlx_xpm_file_to_image(cub->mlx, cub->xpm[i], \
			&(cub->img2[i].width), &(cub->img2[i].height));
		if (!cub->img2[i].img_ptr)
			exit_cub(cub, 1, "Error\ncan't convert xpf file to img\n");
		address = (int *) mlx_get_data_addr(cub->img2[i].img_ptr, &cub->img2[i].bits_per_pixel,
			&cub->img2[i].line_length, &cub->img2[i].endian);
		cub->img2[i].address = address;
		if (!cub->img2[i].address)
			exit_cub(cub, 1, "Error\ncouldn't get img address\n");
		fill_textures(cub, i);
		i++;
	}
	return (0);
}

