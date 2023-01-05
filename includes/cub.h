/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:31:15 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/05 01:32:28 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <sys/time.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include "../parsing/get_next_line/get_next_line.h"
# include "../parsing/libft/libft.h"

//linux
// # define RIGHT_KEY 65363//124
// # define LEFT_KEY 65361//123
// # define UP_KEY 126
// # define DOWN_KEY 125
// # define ESC 65307//53
// # define W 1491//13
// # define A 1492//0
// # define S 1493 //1
// # define D 1514 //2
//mac
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define UP_KEY 126
# define DOWN_KEY 125
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define TILE_SIZE 64
# define NUM_RAYS 1000
# define INT_MAX 2147483647

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		ll;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	move_speed;
	double	rot_angle;
	double	turn_direction;
	double	walk_ud_dir;
	double	walk_rl_dir;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_x;
	double	wall_y;
	double	distance;
	int		hit_v_h;
	int		is_down;
	int		is_up;
	int		is_right;
	int		is_left;
	char	ray_dir;
}	t_ray;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		mlx_img;
	char		**map;
	int			map_h;
	int			map_w;
	int			win_w;
	int			win_h;
	t_player	player;
	t_ray		ray;
	double		fov;
	double		scale;
}	t_mlx;

typedef struct s_dda
{
	int		dx;
	int		dy;
	int		steps;
	int		i;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
	float	start_x;
	float	start_y;
}	t_dda;

typedef struct s_raycast
{
	double xintercept;
	double yintercept;
	double xstep;
	double ystep;
	double next_horz_touch_x;
	double next_horz_touch_y;
	double found_horz_wall_hit;
	double found_vert_wall_hit;
	double next_vert_touch_x;
	double next_vert_touch_y;
	double horz_hit_distance;
	double vert_hit_distance;
	double horz_wall_hit_x;
	double horz_wall_hit_y;
	double vert_wall_hit_x;
	double vert_wall_hit_y;
}	t_raycast;

/* parsing*/

int			count_lines(char *argv[]);
char		**ft_parse(char *argv[]);
void		count_length(t_mlx *mlx);
void		draw_map(t_mlx *mlx);

/*			init		*/
t_ray		init_ray(double ray_angle);
t_player	init_player(void);
t_mlx		*init_mlx(char *argv[]);

/*				Math		*/
void		ddaline(int x1, int y1, int x2, int y2, t_mlx *mlx);
double		distance_between_points(double x1, double y1, double x2, double y2);
double		normalize_angle(double angle);
/*				keys			*/
int			key_press(int key, t_mlx *mlx);
void		move_forward(t_mlx *mlx);
void		move_backward(t_mlx *mlx);
void		move_left(t_mlx *mlx);
void		move_right(t_mlx *mlx);
void		rotate_right(t_mlx *mlx);
void		rotate_left(t_mlx *mlx);
int			key_released(int key, t_mlx *mlx);
int			ft_exit(t_mlx *mlx, int is_esc);
void		update(t_mlx *mlx);

/*				not specified yet		*/
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*			Draw minimap			*/
void		draw_map(t_mlx *mlx);
void		draw_player(t_mlx *mlx);
void		draw_square(t_mlx *mlx, int x, int y, int color, int is_p);
int			has_wall_at(double x, double y, t_mlx *mlx);

/*			raycasting				*/
void		init_casting(t_mlx *mlx);
void		draw_rays(t_mlx *mlx);
void		cast_ray(t_mlx *mlx, t_ray *ray);
void		cast_vert_ray(t_mlx *mlx, t_ray *ray, t_raycast *rcst);
void		cast_horz_ray(t_mlx *mlx, t_ray *ray, t_raycast *rcst);
void		cast_ray(t_mlx *mlx, t_ray *ray);

/*			rendring walls			*/
void		render_walls(t_mlx *mlx);
void		draw_rect(t_mlx *mlx, int x, int y, int width, int height);
void		get_ray_direction(t_ray *ray);
#endif
