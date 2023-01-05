/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:23:15 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/05 10:57:30 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	cast_ray(t_mlx *mlx, t_ray *ray)
{
	t_raycast	*rcst;

	rcst = malloc(sizeof(t_raycast));
	leaks_removal(&mlx->leak, rcst);
	cast_horz_ray(mlx, ray, rcst);
	cast_vert_ray(mlx, ray, rcst);
	if (rcst->found_h_wall)
		rcst->h_dist = distance_between_points(mlx->player.x, mlx->player.y,
				rcst->h_hit_x, rcst->h_hit_y);
	else
		rcst->h_dist = INT_MAX;
	if (rcst->found_v_wall)
		rcst->v_dist = distance_between_points(mlx->player.x, mlx->player.y,
				rcst->v_hit_x, rcst->v_hit_y);
	else
		rcst->v_dist = INT_MAX;
	detect_distance(ray, rcst);
}

void	init_tools(t_mlx *mlx, t_wall *wall)
{
	mlx->ray = init_ray(wall->ray_angle);
	cast_ray(mlx, &mlx->ray);
	get_ray_direction(&mlx->ray);
	wall->true_dist = mlx->ray.distance
		* cos(wall->ray_angle - mlx->player.rot_angle);
	wall->dist_proj = (mlx->win_w / 2) / tan(mlx->fov / 2);
	wall->wall_h = (TILE_SIZE / wall->true_dist) * wall->dist_proj;
	if (wall->wall_h < mlx->win_h)
	{
		wall->start = (mlx->win_h / 2) - wall->wall_h / 2;
		wall->end = (mlx->win_h / 2) + wall->wall_h / 2;
	}
	else
	{
		wall->start = 0;
		wall->end = mlx->win_h;
	}
}

void	ceil_floor(t_mlx *mlx, t_wall *wall)
{
	int		y;

	y = 0;
	while (y < wall->start)
	{
		my_mlx_pixel_put(&mlx->mlx_img, wall->i, y, 0x87ceeb);
		y++;
	}
	y = wall->end;
	while (y < mlx->win_h)
	{
		my_mlx_pixel_put(&mlx->mlx_img, wall->i, y, 0x654321);
		y++;
	}
}

void	draw_wall(t_mlx *mlx)
{
	t_wall	wall;

	wall.i = 0;
	wall.ray_angle = mlx->player.rot_angle - (mlx->fov / 2);
	while (wall.i < mlx->num_rays)
	{
		init_tools(mlx, &wall);
		ceil_floor(mlx, &wall);
		wall.j = wall.start;
		while (wall.j < wall.end)
		{
			my_mlx_pixel_put(&mlx->mlx_img, wall.i, wall.j, 0x808080);
			wall.j++;
		}
		wall.ray_angle += mlx->fov / mlx->num_rays;
		wall.i++;
	}
}

void	start_walls(t_mlx *mlx)
{
	mlx->mlx_img.img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	mlx->mlx_img.addr = mlx_get_data_addr(mlx->mlx_img.img, &mlx->mlx_img.bpp,
			&mlx->mlx_img.ll, &mlx->mlx_img.endian);
	draw_wall(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img.img, 0, 0);
}
