/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:08 by hakaddou          #+#    #+#             */
/*   Updated: 2024/10/09 09:13:07 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rerender(t_cub *cub)
{
	update(cub);
	render(cub);
}

void	check_controls(int key, t_cub *cub)
{
    if (key == DOWN_AROW || key == UP_AROW)
        change_hover_state(cub->control_box.buttons, key);
    if (key == C_KEY)
        cub->keys.c = !(cub->keys.c);
}

int	keys_handler(int key, t_cub *cub)
{
	check_for_exit(key, cub);
	check_player_movement(key, cub);
	check_direction(key, cub);
	check_full_screen(key, cub);
	check_quitting_mini_map(key, cub);
	check_tracking(key, cub);
	check_map_scaling(key, cub);
	check_aiming(key, cub);
	check_controls(key, cub);
	rerender(cub);
	return (0);
}

int	keys_released(int key, t_cub *cub)
{
	if (key == A_KEY)
		cub->keys.up = false;
	if (key == D_KEY)
		cub->keys.down = false;
	if (key == W_KEY)
		cub->keys.up = false;
	if (key == S_KEY)
		cub->keys.down = false;
	if (key == LEFT_AROW)
		cub->keys.left = false;
	if (key == RIGHT_AROW)
		cub->keys.right = false;
	if (key == A_KEY)
		cub->keys.left = false;
	if (key == SHIFT || key == SHIFT - 1)
	{
		cub->player.dist_proj_plane = ((WINDOW_WIDTH / 2)
				/ tan(cub->player.fov / 2));
		cub->keys.aim = false;
		rerender(cub);
	}
	return (0);
}

int	render_loop(t_cub *cub)
{
    (cub->keys.up == false) && (cub->player.walkdirection = 0, 0);
    (cub->keys.down == false) && (cub->player.walkdirection = 0, 0);
    (cub->keys.right == false && cub->keys.m_right == false) && (cub->player.turndirection = 0, 0);
    (cub->keys.left == false && cub->keys.m_left == false) && (cub->player.turndirection = 0, 0);
    (cub->keys.up == true) && (cub->player.walkdirection = 1, 0);
    (cub->keys.down == true) && (cub->player.walkdirection = -1, 0);
    (cub->keys.right == true || cub->keys.m_right == true) && (cub->player.turndirection = 1, 0);
    (cub->keys.left == true || cub->keys.m_left == true) && (cub->player.turndirection = -1, 0);
    (cub->keys.aim) && (check_anim_aim(cub), 0);
    
    (ft_memchr(&cub->keys, 1, sizeof(t_keys))) && (rerender(cub), 0);
    
    return (0);
}


void	hook_keys(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0, exit_app, cub);
	mlx_hook(cub->win, 2, 0, keys_handler, cub);
	mlx_hook(cub->win, 3, 0, keys_released, cub);
	mlx_loop_hook(cub->mlx, render_loop, cub);
}
