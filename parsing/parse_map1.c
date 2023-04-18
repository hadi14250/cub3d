/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:35 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 09:15:36 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*take_map_input(int fd, t_cub *cub)
{
	t_buff	h;

	null_params(&h.tmp, &h.total, &h.line);
	while (1)
	{
		h.i = get_next_line(fd);
		if (!h.i)
			break ;
		h.tmp = h.line;
		h.line = gl_strjoin(h.i, "\n");
		h.tmp = free_null(h.tmp);
		h.tmp = h.total;
		h.total = gl_strjoin(h.total, h.line);
		free_params(&h.line, &h.tmp, &h.i);
	}
	if (!h.total)
		exit_cub(cub, 1, "Error\ncan't have empty map\n");
	return (h.total);
}

void	realloc_map(t_cub *cub)
{
	char	*temp;
	int		len;

	check_for_lines(cub);
	len = return_split_len(&cub->map[cub->max]);
	temp = ft_strsjoin(len, &cub->map[cub->max], "\n");
	cub->map_1d = free_null(cub->map_1d);
	cub->map_1d = temp;
	temp = ft_maptrim(cub->map_1d, "\n\r\f\v");
	cub->map_1d = free_null(cub->map_1d);
	cub->map_1d = temp;
}

void	check_map_pos(t_cub *cub, char **half_map)
{
	int	i;

	i = cub->max - 1;
	if (i <= 1)
		exit_cub(cub, 1, "Error\nInvalid map\n");
	if (!half_map || !half_map[0])
		exit_cub(cub, 1, "Error\nunorganized map\n");
	while (i >= 0)
	{
		if (ft_strnstr(cub->map[i], "111", ft_strlen(cub->map[i])))
		{
			if (!ft_strnstr(cub->map[i], cub->map[cub->floor_pos],
					ft_strlen(cub->map[i]))
				&& !ft_strnstr(cub->map[i], cub->map[cub->ceiling_pos],
					ft_strlen(cub->map[i])))
				exit_cub(cub, 1, "Error\ninvalid map\n");
		}
		i--;
	}
	realloc_map(cub);
}

void	check_pos_helper(t_cub *cub)
{
	int		i;
	char	**split;

	split = cub->map;
	i = -1;
	while (split[++i] != NULL)
	{
		if (ft_strnstr(split[i], "F", ft_strlen(split[i])))
		{
			cub->floor_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
		if (ft_strnstr(split[i], "C", ft_strlen(split[i])))
		{
			cub->ceiling_pos = i;
			if (i > cub->max)
				cub->max = i;
		}
	}
}

void	check_other_format_1d(t_cub *cub)
{
	int		i[4];

	i[0] = -1;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	while (cub->map_1d[++i[0]] != '\0')
	{
		if (is_valid_char(cub->map_1d[i[0]]))
			i[1]++;
		else
		{
			if (i[3] == 0)
				printf("Error\ninvalid character(s): ");
			printf("->%c<- in column %d, ", cub->map_1d[i[0]], i[2] + 1);
			i[3]++;
		}
		if (cub->map_1d[i[0]] == '\n')
			i[2]++;
	}
	if (i[1] != i[0])
		exit_cub(cub, 1, "\n");
}
