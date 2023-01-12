/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:04:58 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/11 23:36:15 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	move_forward(t_mlx *mlx)
{
	double	step;
	double	new_x;
	double	new_y;

	new_x = mlx->player.x;
	new_y = mlx->player.y;
	mlx->player.walk_ud_dir = 1;
	step = mlx->player.move_speed * mlx->player.walk_ud_dir;
	new_x += step * cos(mlx->player.rot_angle);
	new_y += step * sin(mlx->player.rot_angle);
	if (!is_wall(new_x, new_y, mlx))
	{
		mlx->player.x = new_x;
		mlx->player.y = new_y;
	}
}

void	move_backward(t_mlx *mlx)
{
	double	step;
	double	new_x;
	double	new_y;

	new_x = mlx->player.x;
	new_y = mlx->player.y;
	mlx->player.walk_ud_dir = -1;
	step = mlx->player.move_speed * mlx->player.walk_ud_dir;
	new_x += step * cos(mlx->player.rot_angle);
	new_y += step * sin(mlx->player.rot_angle);
	if (!is_wall(new_x, new_y, mlx))
	{
		mlx->player.x = new_x;
		mlx->player.y = new_y;
	}
}

void	move_left(t_mlx *mlx)
{
	double	step;
	double	new_x;
	double	new_y;

	new_x = mlx->player.x;
	new_y = mlx->player.y;
	mlx->player.walk_rl_dir = -1;
	step = mlx->player.move_speed * mlx->player.walk_rl_dir;
	new_x -= step * cos(mlx->player.rot_angle - M_PI_2);
	new_y -= step * sin(mlx->player.rot_angle - M_PI_2);
	if (!is_wall(new_x, new_y, mlx))
	{
		mlx->player.x = new_x;
		mlx->player.y = new_y;
	}
}

void	move_right(t_mlx *mlx)
{
	double	step;
	double	new_x;
	double	new_y;

	new_x = mlx->player.x;
	new_y = mlx->player.y;
	mlx->player.walk_rl_dir = 1;
	step = mlx->player.move_speed * mlx->player.walk_rl_dir;
	new_x += step * cos(mlx->player.rot_angle + M_PI_2);
	new_y += step * sin(mlx->player.rot_angle + M_PI_2);
	if (!is_wall(new_x, new_y, mlx))
	{
		mlx->player.x = new_x;
		mlx->player.y = new_y;
	}
}

void	update(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img.img);
	start_walls(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img.img, 0, 0);
}
