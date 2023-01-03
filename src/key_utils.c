/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:04:58 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/03 08:58:49 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	move_forward(t_mlx *mlx)
{
	double step;
	double new_x;
	double new_y;

	new_x = mlx->player.x;
	new_y = mlx->player.y;
	mlx->player.walk_ud_dir = 1;
	step = mlx->player.move_speed * mlx->player.walk_ud_dir;
	new_x -= step * cos(mlx->player.rot_angle);
	new_y -= step * sin(mlx->player.rot_angle);
	if (!has_wall_at(new_x, new_y, mlx))
	{
		mlx->player.x = new_x;
		mlx->player.y = new_y;
	}
}

void	move_backward(t_mlx *mlx)
{
	double step;
	double new_x;
	double new_y;

	new_x = mlx->player.x;
	new_y = mlx->player.y;
	mlx->player.walk_ud_dir = -1;
	step = mlx->player.move_speed * mlx->player.walk_ud_dir;
	new_x -= step * cos(mlx->player.rot_angle);
	new_y -= step * sin(mlx->player.rot_angle);
	if (!has_wall_at(new_x, new_y, mlx))
	{
		mlx->player.x = new_x;
		mlx->player.y = new_y;
	}
}

void	move_left(t_mlx *mlx)
{
	double step;
	double new_x;
	double new_y;

	new_x = mlx->player.x;
	new_y = mlx->player.y;
	mlx->player.walk_rl_dir = -1;
	step = mlx->player.move_speed * mlx->player.walk_rl_dir;
	new_x += step * cos(normalize_angle(mlx->player.rot_angle - M_PI_2));
	new_y += step * sin(normalize_angle(mlx->player.rot_angle - M_PI_2));
	if (!has_wall_at(new_x, new_y, mlx))
	{
		mlx->player.x = new_x;
		mlx->player.y = new_y;
	}
}

void	move_right(t_mlx *mlx)
{
		double step;
		double new_x;
		double new_y;
	
		new_x = mlx->player.x;
		new_y = mlx->player.y;
		mlx->player.walk_rl_dir = 1;
		step = mlx->player.move_speed * mlx->player.walk_rl_dir;
		new_x += step * cos(normalize_angle(mlx->player.rot_angle - M_PI_2));
		new_y += step * sin(normalize_angle(mlx->player.rot_angle - M_PI_2));
		if (!has_wall_at(new_x, new_y, mlx))
		{
			mlx->player.x = new_x;
			mlx->player.y = new_y;
		}
}

void	update(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img.img);
	// mlx->mlx_img.img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	// mlx->mlx_img.addr = mlx_get_data_addr(mlx->mlx_img.img, &mlx->mlx_img.bpp,
	// 		&mlx->mlx_img.ll, &mlx->mlx_img.endian);
	render_walls(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img.img, 0, 0);
}