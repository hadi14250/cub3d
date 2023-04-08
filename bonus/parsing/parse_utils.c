/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:59:19 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/07 22:23:07 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free(char ***array)
{
	int	i;

	i = 0;
	if (!*array)
		return ;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

int	ft_array_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**ft_reallocation(char **pointer, int size)
{
	int		i;
	char	**new_pointer;

	i = 0;
	new_pointer = malloc(sizeof(char *) * size);
	if (!new_pointer)
		return (NULL);
	while (pointer[i])
	{
		new_pointer[i] = pointer[i];
		i++;
	}
	new_pointer[i] = NULL;
	new_pointer[i + 1] = NULL;
	free(pointer);
	return (new_pointer);
}

void	print_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

unsigned long	rgb_to_hex(int red, int green, int blue, t_cub *cub)
{
	unsigned long temp;
	if (red > 255 || green > 255 || blue > 255 ||
		red < 0 || green < 0 || blue < 0)
		cub->color_flag = true;
	temp = (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
	return (temp);
}
