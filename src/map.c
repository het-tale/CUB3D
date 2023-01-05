/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:10:45 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/05 02:48:02 by het-tale         ###   ########.fr       */
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
				draw_square(mlx, (j * TILE_SIZE), (i * TILE_SIZE), 0);
			j++;
		}
		i++;
	}
	draw_square(mlx, mlx->player.x, mlx->player.y, 1);
}

void	square_conditions(t_mlx *mlx, int *size, unsigned int *color, int is_p)
{
	if (is_p == 1)
	{
		*size = TILE_SIZE / 16;
		*color = mlx->player.plyr_color;
	}
	else
	{
		*size = TILE_SIZE;
		*color = mlx->map_color;
	}
}

void	draw_square(t_mlx *mlx, int x, int y, int is_p)
{
	int				i;
	int				j;
	int				size;
	unsigned int	color;

	i = 0;
	square_conditions(mlx, &size, &color, is_p);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(&mlx->mlx_img, mlx->scale * (x + j),
				mlx->scale * (y + i), color);
			j++;
		}
		i++;
	}
}

int	is_wall(double x, double y, t_mlx *mlx)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (i < 0 || i >= mlx->map_w || j < 0 || j >= mlx->map_h)
		return (1);
	if (mlx->map[j][i] == '1')
		return (1);
	return (0);
}
