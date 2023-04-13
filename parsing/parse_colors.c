/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:34:04 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 07:42:43 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_rgb(t_cub *cub)
{
	check_floor_ceiling(cub);
	check_north_south(cub);
	east_west(cub);
	cub->rgb = callocer(5, sizeof(char *), cub);
	cub->c_rgb = ft_strnstr(cub->map_1d, "C", cub->map_1d_len);
	cub->c_rgb = ft_tex_dup(cub->c_rgb);
	trim_comma(cub->c_rgb);
	cub->f_rgb = ft_strnstr(cub->map_1d, "F", cub->map_1d_len);
	cub->f_rgb = ft_tex_dup(cub->f_rgb);
	trim_comma(cub->f_rgb);
	rgb(cub, ft_strnstr(cub->c_rgb, "C", ft_strlen(cub->c_rgb)) + 1, 'C');
	rgb(cub, ft_strnstr(cub->f_rgb, "F", ft_strlen(cub->f_rgb)) + 1, 'F');
	cub->c_rgb = free_null(cub->c_rgb);
	cub->f_rgb = free_null(cub->f_rgb);
	convert_colors(cub, cub->rgb[1], 0);
	convert_colors(cub, cub->rgb[0], 1);
}

// int	*check_rgb(char **rgb_array)
// {
// 	int	i;
// 	int	*rgb;

// 	i = 0;
// 	rgb = malloc(sizeof(int) * 4);
// 	if (!rgb)
// 		return (NULL);
// 	while (rgb_array[i])
// 	{
// 		rgb[i] = ft_atoi(rgb_array[i]);
// 		if (rgb[i] < 0 || rgb[i] > 255)
// 			return (NULL);
// 		i++;
// 	}
// 	rgb[i] = 0;
// 	return (rgb);
// }

int	rgb(t_cub *cub, char *line, char flag)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (ft_array_length(tokens) != 3)
	{
		free_split(&tokens);
		exit_cub(cub, 1, "Error\nRgb validation failed\n");
	}
	if (flag == 'F')
		cub->rgb[0] = ft_strdup(line);
	else if (flag == 'C')
		cub->rgb[1] = ft_strdup(line);
	free_split(&tokens);
	return (0);
}
