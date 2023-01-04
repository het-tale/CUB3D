/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:10:45 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/04 11:22:16 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map_h)
	{
		j = 0;
		while (j < mlx->map_w)
		{
			if (mlx->map[i][j] == '1')
				draw_square(mlx, (j * TILE_SIZE), (i * TILE_SIZE), 0xFFFFFF, 0);
			j++;
		}
		i++;
	}
	draw_player(mlx);
}

void	draw_player(t_mlx *mlx)
{
	draw_square(mlx, mlx->player.x, mlx->player.y, 0xFF0000, 1);
	ddaline(mlx->player.x, mlx->player.y, mlx->player.x + cos(mlx->player.rot_angle) * 30,
	mlx->player.y + sin(mlx->player.rot_angle) * 30, mlx);
}

void	draw_square(t_mlx *mlx, int x, int y, int color, int is_p)
{
	int i;
	int j;
	int	size;

	i = 0;
	if (is_p == 1)
		size = TILE_SIZE / 16;
	else
		size = TILE_SIZE;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(&mlx->mlx_img, mlx->scale * (x + j), mlx->scale * (y + i), color);
			j++;
		}
		i++;
	}
}

int	has_wall_at(double x, double y, t_mlx *mlx)
{
	int i;
	int j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (i < 0 || i >= mlx->map_w || j < 0 || j >= mlx->map_h)
		return (1);
	if (mlx->map[j][i] == '1')
		return (1);
	return (0);
}
