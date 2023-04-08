/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:53 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/08 13:25:03 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*free_img(void *img_ptr, void *mlx)
{
	if (img_ptr != NULL)
		mlx_destroy_image(mlx, img_ptr);
	return (NULL);
}

void	*free_window(void *mlx, void *win)
{
	if (win != NULL)
	{
		mlx_destroy_window(mlx, win);
		printf("Window destryoed\n");
	}
	return (NULL);
}

// return a new image, if the old image isn't free it'll free it first then
// overwrite with new image
void	*cub_new_img(t_img *img, void *mlx, int width, int height)
{
	if (!img)
	{
		printf("img is NULL in cub_new_image\n");
		exit(1);
	}
	if (img->img_ptr != NULL)
		mlx_destroy_image(mlx, img->img_ptr);
	img->img_ptr = mlx_new_image(mlx, width, height);
	if (!img->img_ptr)
		return (NULL);
	img->address = mlx_get_data_addr(
			img->img_ptr,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian
			);
	return (img->img_ptr);
}

void	init_mlx_utils(t_cub *cub)
{
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if (!cub->win)
		exit_cub(cub, 1, "Error\ncan't initialise window\n");
	cub->img.img_ptr = NULL;
	cub->img.img_ptr = cub_new_img (&cub->img, cub->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!cub->img.img_ptr)
		exit_cub(cub, 1, "Error\ncan't initialise image\n");
}

void	ft_swap(double *a, double *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
