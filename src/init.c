/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:29:06 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/19 00:50:15 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_ray	init_ray(double ray_angle)
{
	t_ray	ray;

	ray.ray_angle = normalize_angle(ray_angle);
	ray.wall_x = 0;
	ray.wall_y = 0;
	ray.distance = 0;
	if (ray.ray_angle > 0 && ray.ray_angle < M_PI)
		ray.is_down = 1;
	else
		ray.is_down = 0;
	ray.is_up = !ray.is_down;
	if (ray.ray_angle < 0.5 * M_PI || ray.ray_angle > 1.5 * M_PI)
		ray.is_right = 1;
	else
		ray.is_right = 0;
	ray.is_left = !ray.is_right;
	return (ray);
}

t_player	init_player(t_mlx *mlx)
{
	t_player	plyr;

	plyr.x = mlx->player.x * TILE_SIZE + TILE_SIZE / 2;
	plyr.y = mlx->player.y * TILE_SIZE + TILE_SIZE / 2;
	plyr.rot_angle = get_player_angle(mlx->player.direction);
	plyr.rot_speed = 7 * (M_PI / 180);
	plyr.move_speed = 10;
	plyr.turn_direction = 0;
	plyr.walk_ud_dir = 0;
	plyr.walk_rl_dir = 0;
	plyr.plyr_color = 0xFF0000;
	return (plyr);
}

void	init_parsing(char *argv[], t_mlx *param)
{
	int	fd;

	init(param);
	fd = open(argv[1], O_RDWR);
	get_map(param, fd, argv[1]);
	pos_plyr(param);
	if (!check_elements_map(param))
		ft_error("Error \n > Map Not valid");
}

t_mlx	*init_mlx(char *argv[])
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	leaks_removal(&mlx->leak, mlx);
	init_parsing(argv, mlx);
	mlx->mlx = mlx_init();
	mlx->win_w = mlx->map->width * TILE_SIZE;
	mlx->win_h = mlx->map->height * TILE_SIZE;
	mlx->ceil_color = rgb2int(mlx->colors->ceiling[0],
			mlx->colors->ceiling[1], mlx->colors->ceiling[2]);
	mlx->floor_color = rgb2int(mlx->colors->floor[0],
			mlx->colors->floor[1], mlx->colors->floor[2]);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "CUB");
	mlx->player = init_player(mlx);
	mlx->fov = 60 * (M_PI / 180);
	mlx->scale = 0.1;
	mlx->map_color = 0xFFFFFF;
	mlx->num_rays = mlx->win_w;
	get_textures(mlx);
	start_walls(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img.img, 0, 0);
	return (mlx);
}

void	get_ray_direction(t_ray *ray)
{
	if (ray->is_down && !ray->is_hit_v)
		ray->ray_dir = 'S';
	else if (!ray->is_hit_v)
		ray->ray_dir = 'N';
	else if (ray->is_right)
		ray->ray_dir = 'E';
	else
		ray->ray_dir = 'W';
}
