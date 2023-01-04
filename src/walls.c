/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:23:15 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/04 10:51:13 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	get_ray_direction(t_ray *ray)
{
	if (ray->is_ray_facing_down && !ray->was_hit_vertical)
		ray->ray_dir = 'S';
	else if (!ray->was_hit_vertical)
		ray->ray_dir = 'N';
	else if (ray->is_ray_facing_right)
		ray->ray_dir = 'E';
	else
		ray->ray_dir = 'W';
}

void	render_walls(t_mlx *mlx)
{
	int	i;
	double wall_strip_height;
	double dist_proj;
	double ray_angle;
	int	j;
	int	start;
	int	end;

	mlx->mlx_img.img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	mlx->mlx_img.addr = mlx_get_data_addr(mlx->mlx_img.img, &mlx->mlx_img.bpp,
			&mlx->mlx_img.ll, &mlx->mlx_img.endian);
	i = 0;
	ray_angle = mlx->player.rot_angle - (mlx->fov / 2);
	while (i < NUM_RAYS)
	{
		mlx->ray = init_ray(ray_angle);
		cast_ray(mlx, &mlx->ray);
		get_ray_direction(&mlx->ray);
		//my_mlx_pixel_put(&mlx->mlx_img, i, 1, 0xFFFFFF);
		dist_proj = (mlx->win_w / 2) / tan(mlx->fov / 2);
		wall_strip_height = (TILE_SIZE / mlx->ray.distance) * dist_proj;
		if (wall_strip_height < mlx->win_h)
		{
			start = (mlx->win_h / 2) - wall_strip_height / 2;
			end = (mlx->win_h / 2) + wall_strip_height / 2;
		}
		else
		{
			start = 0;
			end = mlx->win_h;
		}
		j = start;
		while (j < end)
		{
			my_mlx_pixel_put(&mlx->mlx_img, i, j, 0x808080);
			j++;
		}
		ray_angle += mlx->fov / NUM_RAYS;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img.img, 0, 0);
}