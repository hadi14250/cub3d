/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:34:04 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/10 03:17:25 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	*check_rgb(char **rgb_array)
{
	int	i;
	int	*rgb;

	i = 0;
	rgb = malloc(sizeof(int) * 4);
	if (!rgb)
		return (NULL);
	while (rgb_array[i])
	{
		rgb[i] = ft_atoi(rgb_array[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (NULL);
		i++;
	}
	rgb[i] = 0;
	return (rgb);
}

// void	convert_colors(t_cub *cub, int *rgb, int flag)
// {
// 	unsigned long	temp;

// 	if (flag == 0)
// 	{
// 		temp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
// 		cub->floor = temp;
// 	}
// 	if (flag == 1)
// 	{
// 		temp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
// 		cub->ceiling = temp;
// 	}
// }

// int	init_colors(t_cub *cub)
// {
// 	int		i;
// 	int		*rgb;
// 	char	**temp;

// 	i = 0;
// 	while (cub->rgb[i])
// 	{
// 		temp = ft_split(cub->rgb[i], ',');
// 		if (ft_array_length(temp) != 3)
// 		{
// 			printf("messed up RGB size\n");
// 			exit(1);
// 		}
// 		if (!temp)
// 			return (1);
// 		rgb = check_rgb(temp);
// 		if (!rgb)
// 		{
// 			free(rgb);
// 			return (1);
// 		}
// 		convert_colors(cub, rgb, i);
// 		ft_free(&temp);
// 		free(rgb);
// 		i++;
// 	}
// 	return (0);
// }
