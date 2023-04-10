/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:36:56 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/10 16:39:11 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	arg_count(int ac)
{
	if (ac != 2)
	{
		printf("Error\n[usage]: ./cub3d cubfile\n");
		exit(EXIT_FAILURE);
	}
}

int	ft_close(int fd)
{
	if (fd > 2)
		close(fd);
	return (-1);
}

void	null_params(char **tmp, char **total, char **line)
{
	*tmp = NULL;
	*total = NULL;
	*line = NULL;
}

void	free_params(char **line, char **tmp, char **input)
{
	*line = free_null(*line);
	*tmp = free_null(*tmp);
	*input = free_null(*input);
}

int	return_len(char **split)
{
	int	i;
	int	d;

	d = 0;
	i = -1;
	while (split[++i] != NULL)
		d += ft_strlen(split[i]) + 1;
	return (d);
}
