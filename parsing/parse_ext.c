/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:04:57 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/10 16:21:20 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_file_ext(t_cub *cub, char *map_file)
{
	int	i;

	i = ft_strlen(map_file);
	if (!(map_file[i - 1] == 'b' && map_file[i - 2] == 'u'
			&& map_file[i - 3] == 'c' && map_file[i - 4] == '.') || cub->fd < 0)
		exit_cub(cub, 1, "Error\nInvalid file ext\n");
	return (0);
}
