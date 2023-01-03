/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:57:09 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/03 08:42:08 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_exit(t_mlx *mlx, int is_esc)
{
	if (is_esc == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	}
	exit(0);
}

void	rotate_left(t_mlx *mlx)
{
	mlx->player.turn_direction = -1;
	mlx->player.rot_angle += mlx->player.turn_direction * mlx->player.rot_speed;
}

void	rotate_right(t_mlx *mlx)
{
	mlx->player.turn_direction = 1;
	mlx->player.rot_angle += mlx->player.turn_direction * mlx->player.rot_speed;
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_exit(mlx, ESC);
	else if (key == W)
		move_forward(mlx);
	else if (key == S)
		move_backward(mlx);
	else if (key == A)
		move_left(mlx);
	else if (key == D)
		move_right(mlx);
	else if (key == RIGHT_KEY)
		rotate_right(mlx);
	else if (key == LEFT_KEY)
		rotate_left(mlx);
	update(mlx);
	return (0);
}

int	key_released(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_exit(mlx, ESC);
	else if (key == W)
		mlx->player.walk_ud_dir = 0;
	else if (key == S)
		mlx->player.walk_ud_dir = 0;
	else if (key == A)
		mlx->player.walk_rl_dir = 0;
	else if (key == D)
		mlx->player.walk_rl_dir = 0;
	else if (key == RIGHT_KEY)
		mlx->player.turn_direction = 0;
	else if (key == LEFT_KEY)
		mlx->player.turn_direction = 0;
	update(mlx);
	return (0);
}