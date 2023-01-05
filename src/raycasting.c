/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:03:14 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/05 01:32:50 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	cast_horz_ray(t_mlx *mlx, t_ray *ray, t_raycast *rcst)
{
	rcst->found_horz_wall_hit = 0;
	rcst->yintercept = floor(mlx->player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_down)
		rcst->yintercept += TILE_SIZE;
	rcst->xintercept = mlx->player.x + (rcst->yintercept - mlx->player.y) / tan(ray->ray_angle);
	rcst->ystep = TILE_SIZE;
	if (ray->is_up)
		rcst->ystep *= -1;
	rcst->xstep = TILE_SIZE / tan(ray->ray_angle);
	if (ray->is_left && rcst->xstep > 0)
		rcst->xstep *= -1;
	else if (ray->is_right && rcst->xstep < 0)
		rcst->xstep *= -1;
	rcst->next_horz_touch_x = rcst->xintercept;
	rcst->next_horz_touch_y = rcst->yintercept;
	while (rcst->next_horz_touch_x >= 0 && rcst->next_horz_touch_x <= mlx->win_w && rcst->next_horz_touch_y >= 0 && rcst->next_horz_touch_y <= mlx->win_h)
	{
		if (ray->is_up)
			rcst->next_horz_touch_y--;
		if (has_wall_at(rcst->next_horz_touch_x, rcst->next_horz_touch_y, mlx))
		{
			rcst->found_horz_wall_hit = 1;
			rcst->horz_wall_hit_x = rcst->next_horz_touch_x;
			rcst->horz_wall_hit_y = rcst->next_horz_touch_y;
			break ;
		}
		else
		{
			rcst->next_horz_touch_x += rcst->xstep;
			rcst->next_horz_touch_y += rcst->ystep;
		}
	}
}

void	cast_vert_ray(t_mlx *mlx, t_ray *ray, t_raycast *rcst)
{
	
	//vertical intersection
	rcst->found_vert_wall_hit = 0;
	rcst->xintercept = floor(mlx->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_right)
		rcst->xintercept += TILE_SIZE;
	rcst->yintercept = mlx->player.y + (rcst->xintercept - mlx->player.x) * tan(ray->ray_angle);
	rcst->xstep = TILE_SIZE;
	if (ray->is_left)
		rcst->xstep *= -1;
	rcst->ystep = TILE_SIZE * tan(ray->ray_angle);
	if (ray->is_up && rcst->ystep > 0)
		rcst->ystep *= -1;
	else if (ray->is_down && rcst->ystep < 0)
		rcst->ystep *= -1;
	rcst->next_vert_touch_x = rcst->xintercept;
	rcst->next_vert_touch_y = rcst->yintercept;
	while (rcst->next_vert_touch_x >= 0 && rcst->next_vert_touch_x <= mlx->win_w && rcst->next_vert_touch_y >= 0 && rcst->next_vert_touch_y <= mlx->win_h)
	{
		if (ray->is_left)
			rcst->next_vert_touch_x--;
		if (has_wall_at(rcst->next_vert_touch_x, rcst->next_vert_touch_y, mlx))
		{
			rcst->found_vert_wall_hit = 1;
			rcst->vert_wall_hit_x = rcst->next_vert_touch_x;
			rcst->vert_wall_hit_y = rcst->next_vert_touch_y;
			break ;
		}
		else
		{
			rcst->next_vert_touch_x += rcst->xstep;
			rcst->next_vert_touch_y += rcst->ystep;
		}
	}
}

void	cast_ray(t_mlx *mlx, t_ray *ray)
{
	t_raycast *rcst;

	rcst = malloc(sizeof(t_raycast));
	cast_horz_ray(mlx, ray, rcst);
	cast_vert_ray(mlx, ray, rcst);
	//calculate the distance
	if (rcst->found_horz_wall_hit)
		rcst->horz_hit_distance = distance_between_points(mlx->player.x, mlx->player.y, rcst->horz_wall_hit_x, rcst->horz_wall_hit_y);
	else
		rcst->horz_hit_distance = INT_MAX;
	if (rcst->found_vert_wall_hit)
		rcst->vert_hit_distance = distance_between_points(mlx->player.x, mlx->player.y, rcst->vert_wall_hit_x, rcst->vert_wall_hit_y);
	else
		rcst->vert_hit_distance = INT_MAX;
	if (rcst->horz_hit_distance < rcst->vert_hit_distance)
	{
		ray->distance = rcst->horz_hit_distance;
		ray->wall_x = rcst->horz_wall_hit_x;
		ray->wall_y = rcst->horz_wall_hit_y;
		ray->hit_v_h = 0;
	}
	else
	{
		ray->distance = rcst->vert_hit_distance;
		ray->wall_x = rcst->vert_wall_hit_x;
		ray->wall_y = rcst->vert_wall_hit_y;
		ray->hit_v_h = 1;
	}
}