/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:14:05 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 09:07:25 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_tex_dup(const char *s1)
{
	int		i;
	int		d;
	char	*tmp;
	int		size;

	i = 0;
	d = 0;
	size = ft_tex_len((char *)s1);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		tmp[d] = s1[i];
		i++;
		d++;
	}
	tmp[d] = '\0';
	return (tmp);
}

size_t	ft_tex_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	return_split_len(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != NULL)
		;
	return (i);
}

void	trim_map_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = '0';
	}
}

void	exit_cub(t_cub *cub, int code, char *msg)
{
	if (cub->color_buffer)
		cub->color_buffer = free_null(cub->color_buffer);
	if (cub->tex)
		cub->tex = free_null(cub->tex);
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx, cub->img.img_ptr);
	free_texes(cub);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->map_1d)
		cub->map_1d = free_null(cub->map_1d);
	free_split(&cub->map);
	free_split(&cub->xpm);
	free_rgbs(cub);
	cub->c_rgb = free_null(cub->c_rgb);
	cub->f_rgb = free_null(cub->f_rgb);
	cub->fd = ft_close(cub->fd);
	cub->color_buffer = free_null(cub->color_buffer);
	cub->tex = free_null(cub->tex);
	printf("%s", msg);
	exit (code);
}
