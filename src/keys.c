/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:57:09 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/06 21:24:43 by het-tale         ###   ########.fr       */
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
	else if (key == W || key == UP_KEY)
		move_forward(mlx);
	else if (key == S || key == DOWN_KEY)
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
