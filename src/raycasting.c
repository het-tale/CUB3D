/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:03:14 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/05 09:21:15 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	define_horz_data(t_mlx *mlx, t_ray *ray, t_raycast *rcst)
{
	rcst->found_h_wall = 0;
	rcst->y_inter = floor(mlx->player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_down)
		rcst->y_inter += TILE_SIZE;
	rcst->x_inter = mlx->player.x
		+ (rcst->y_inter - mlx->player.y) / tan(ray->ray_angle);
	rcst->y_step = TILE_SIZE;
	if (ray->is_up)
		rcst->y_step *= -1;
	rcst->x_step = TILE_SIZE / tan(ray->ray_angle);
	if (ray->is_left && rcst->x_step > 0)
		rcst->x_step *= -1;
	else if (ray->is_right && rcst->x_step < 0)
		rcst->x_step *= -1;
	rcst->next_h_x = rcst->x_inter;
	rcst->next_h_y = rcst->y_inter;
}

void	define_vert_data(t_mlx *mlx, t_ray *ray, t_raycast *rcst)
{
	rcst->found_v_wall = 0;
	rcst->x_inter = floor(mlx->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_right)
		rcst->x_inter += TILE_SIZE;
	rcst->y_inter = mlx->player.y
		+ (rcst->x_inter - mlx->player.x) * tan(ray->ray_angle);
	rcst->x_step = TILE_SIZE;
	if (ray->is_left)
		rcst->x_step *= -1;
	rcst->y_step = TILE_SIZE * tan(ray->ray_angle);
	if (ray->is_up && rcst->y_step > 0)
		rcst->y_step *= -1;
	else if (ray->is_down && rcst->y_step < 0)
		rcst->y_step *= -1;
	rcst->next_v_x = rcst->x_inter;
	rcst->next_v_y = rcst->y_inter;
}

void	cast_horz_ray(t_mlx *mlx, t_ray *ray, t_raycast *rcst)
{
	define_horz_data(mlx, ray, rcst);
	while (rcst->next_h_x >= 0 && rcst->next_h_x <= mlx->win_w
		&& rcst->next_h_y >= 0 && rcst->next_h_y <= mlx->win_h)
	{
		if (ray->is_up)
			rcst->next_h_y--;
		if (is_wall(rcst->next_h_x, rcst->next_h_y, mlx))
		{
			rcst->found_h_wall = 1;
			rcst->h_hit_x = rcst->next_h_x;
			rcst->h_hit_y = rcst->next_h_y;
			break ;
		}
		else
		{
			rcst->next_h_x += rcst->x_step;
			rcst->next_h_y += rcst->y_step;
		}
	}
}

void	cast_vert_ray(t_mlx *mlx, t_ray *ray, t_raycast *rcst)
{
	define_vert_data(mlx, ray, rcst);
	while (rcst->next_v_x >= 0 && rcst->next_v_x <= mlx->win_w
		&& rcst->next_v_y >= 0 && rcst->next_v_y <= mlx->win_h)
	{
		if (ray->is_left)
			rcst->next_v_x--;
		if (is_wall(rcst->next_v_x, rcst->next_v_y, mlx))
		{
			rcst->found_v_wall = 1;
			rcst->v_hit_x = rcst->next_v_x;
			rcst->v_hit_y = rcst->next_v_y;
			break ;
		}
		else
		{
			rcst->next_v_x += rcst->x_step;
			rcst->next_v_y += rcst->y_step;
		}
	}
}

void	detect_distance(t_ray *ray, t_raycast *rcst)
{
	if (rcst->h_dist < rcst->v_dist)
	{
		ray->distance = rcst->h_dist;
		ray->wall_x = rcst->h_hit_x;
		ray->wall_y = rcst->h_hit_y;
		ray->is_hit_v = 0;
	}
	else
	{
		ray->distance = rcst->v_dist;
		ray->wall_x = rcst->v_hit_x;
		ray->wall_y = rcst->v_hit_y;
		ray->is_hit_v = 1;
	}
}
