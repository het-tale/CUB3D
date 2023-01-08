/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:29:06 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/08 16:29:40 by het-tale         ###   ########.fr       */
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

double	get_player_angle(char c)
{
	double	angle;

	if (c == 'N')
		angle = 1.5 * M_PI;
	else if (c == 'S')
		angle = M_PI_2;
	else if (c == 'W')
		angle = M_PI;
	else
		angle = 0;
	return (angle);
}

t_player	init_player(t_mlx *mlx)
{
	t_player	plyr;

	plyr.x = mlx->player.pos[0] * TILE_SIZE + TILE_SIZE / 2;
	plyr.y = mlx->player.pos[1] * TILE_SIZE + TILE_SIZE / 2;
	plyr.rot_angle = get_player_angle(mlx->player.direction);
	plyr.rot_speed = 3 * (M_PI / 180);
	plyr.move_speed = 10;
	plyr.turn_direction = 0;
	plyr.walk_ud_dir = 0;
	plyr.walk_rl_dir = 0;
	plyr.plyr_color = 0xFF0000;
	return (plyr);
}

t_mlx	*init_mlx(char *argv[])
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	leaks_removal(&mlx->leak, mlx);
	mlx->map = ft_parse(argv, mlx);
	count_length(mlx);
	mlx->map_h = count_lines(argv, mlx);
	mlx->mlx = mlx_init();
	mlx->win_w = mlx->map_w * TILE_SIZE;
	mlx->win_h = mlx->map_h * TILE_SIZE;
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "CUB");
	get_player_coordinates(mlx);
	mlx->player = init_player(mlx);
	mlx->fov = 60 * (M_PI / 180);
	mlx->scale = 0.1;
	mlx->map_color = 0xFFFFFF;
	mlx->num_rays = mlx->win_w;
	mlx->txt[0].t_file = "./textures/n.xpm";
	mlx->txt[1].t_file = "./textures/s.xpm";
	mlx->txt[2].t_file = "./textures/e.xpm";
	mlx->txt[3].t_file = "./textures/w.xpm";
	int i = 0;
	while (i < 4)
	{
		mlx->txt[i].t_image = mlx_xpm_file_to_image(mlx->mlx, mlx->txt[i].t_file, &mlx->txt[i].t_width, &mlx->txt[i].t_height);
		if (!mlx->txt[i].t_image
		|| mlx->txt[i].t_width != TILE_SIZE
		|| mlx->txt[i].t_height != TILE_SIZE)
		{
			int t = write(2, "invalid texture\n", 17);
			(void)t;
			i--;
			while (i > -1)
			{
				mlx_destroy_image(mlx->mlx, mlx->txt[i].t_image);
				i--;
			}
			ft_exit(mlx, 0);
		}
		mlx->txt[i].t_addr = mlx_get_data_addr(mlx->txt[i].t_image, &mlx->txt[i].bpp, &mlx->txt[i].ll, &mlx->txt[i].end);
		i++;
	}
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
