/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 04:34:38 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/19 01:26:09 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	get_textures(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx->txt[i].t_image = mlx_xpm_file_to_image(mlx->mlx, mlx->txt[i].name,
				&mlx->txt[i].width, &mlx->txt[i].height);
		if (!mlx->txt[i].t_image
			|| mlx->txt[i].width != TILE_SIZE
			|| mlx->txt[i].height != TILE_SIZE)
		{
			write(2, "invalid texture\n", 17);
			i--;
			while (i > -1)
			{
				mlx_destroy_image(mlx->mlx, mlx->txt[i].t_image);
				i--;
			}
			ft_exit(mlx, 0);
		}
		mlx->txt[i].t_addr = mlx_get_data_addr(mlx->txt[i].t_image,
				&mlx->txt[i].bpp, &mlx->txt[i].ll, &mlx->txt[i].end);
		i++;
	}
}

void	north_texture(t_mlx *mlx, t_wall *wall)
{
	if (mlx->ray.ray_dir == 'N')
	{
		if (mlx->ray.is_hit_v)
			wall->offset_x = (int)mlx->ray.wall_y % TILE_SIZE;
		else
			wall->offset_x = (int)mlx->ray.wall_x % TILE_SIZE;
		wall->j = wall->start;
		while (wall->j < wall->end)
		{
			wall->offset_y = (wall->j + (wall->wall_h / 2) - mlx->win_h / 2)
				* ((float)mlx->txt[0].height / wall->wall_h);
			wall->texel_color = get_pixel_color(&mlx->txt[0],
					wall->offset_x, wall->offset_y);
			my_mlx_pixel_put(&mlx->mlx_img, wall->i, wall->j,
				wall->texel_color);
			wall->j++;
		}
	}
}

void	south_texture(t_mlx *mlx, t_wall *wall)
{
	if (mlx->ray.ray_dir == 'S')
	{
		if (mlx->ray.is_hit_v)
			wall->offset_x = (int)mlx->ray.wall_y % TILE_SIZE;
		else
			wall->offset_x = (int)mlx->ray.wall_x % TILE_SIZE;
		wall->j = wall->start;
		while (wall->j < wall->end)
		{
			wall->offset_y = (wall->j + (wall->wall_h / 2) - mlx->win_h / 2)
				* ((float)mlx->txt[1].height / wall->wall_h);
			wall->texel_color = get_pixel_color(&mlx->txt[1],
					wall->offset_x, wall->offset_y);
			my_mlx_pixel_put(&mlx->mlx_img, wall->i, wall->j,
				wall->texel_color);
			wall->j++;
		}
	}
}

void	east_texture(t_mlx *mlx, t_wall *wall)
{
	if (mlx->ray.ray_dir == 'E')
	{
		if (mlx->ray.is_hit_v)
			wall->offset_x = (int)mlx->ray.wall_y % TILE_SIZE;
		else
			wall->offset_x = (int)mlx->ray.wall_x % TILE_SIZE;
		wall->j = wall->start;
		while (wall->j < wall->end)
		{
			wall->offset_y = (wall->j + (wall->wall_h / 2) - mlx->win_h / 2)
				* ((float)mlx->txt[2].height / wall->wall_h);
			wall->texel_color = get_pixel_color(&mlx->txt[2],
					wall->offset_x, wall->offset_y);
			my_mlx_pixel_put(&mlx->mlx_img, wall->i, wall->j,
				wall->texel_color);
			wall->j++;
		}
	}
}

void	west_texture(t_mlx *mlx, t_wall *wall)
{
	if (mlx->ray.ray_dir == 'W')
	{
		if (mlx->ray.is_hit_v)
			wall->offset_x = (int)mlx->ray.wall_y % TILE_SIZE;
		else
			wall->offset_x = (int)mlx->ray.wall_x % TILE_SIZE;
		wall->j = wall->start;
		while (wall->j < wall->end)
		{
			wall->offset_y = (wall->j + (wall->wall_h / 2) - mlx->win_h / 2)
				* ((float)mlx->txt[3].height / wall->wall_h);
			wall->texel_color = get_pixel_color(&mlx->txt[3],
					wall->offset_x, wall->offset_y);
			my_mlx_pixel_put(&mlx->mlx_img, wall->i, wall->j,
				wall->texel_color);
			wall->j++;
		}
	}
}
