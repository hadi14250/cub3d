/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:04:57 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/03 17:54:15 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_file_ext(int fd, char *map_file)
{
	int	i;

	i = ft_strlen(map_file);
	if (!(map_file[i - 1] == 'b' && map_file[i - 2] == 'u'
			&& map_file[i - 3] == 'c' && map_file[i - 4] == '.') || fd < 0)
	{
		printf("Invalid file\n");
		close (fd);
		return (1);
	}
	return (0);
}
