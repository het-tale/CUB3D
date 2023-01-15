/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:31:15 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/09 19:24:12 by het-tale         ###   ########.fr       */
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
# include "../parser/includes/parsing.h"

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

// typedef struct s_mlx_img
// {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		endian;
// 	int		ll;
// }	t_img;

// typedef struct s_leaks
// {
// 	void			*leak;
// 	struct s_leaks	*next;
// }	t_leaks;

// typedef struct s_texture
// {
// 	char	*name;
// 	int		width;
// 	int		height;
// 	void	*t_image;
// 	char	*t_addr;
// 	int		bpp;
// 	int		ll;
// 	int		end;
// }	t_texture;

// typedef struct s_player
// {
// 	double			x;
// 	double			y;
// 	char			direction;
// 	int				pos[2];
// 	double			rot_speed;
// 	double			move_speed;
// 	double			rot_angle;
// 	double			turn_direction;
// 	double			walk_ud_dir;
// 	double			walk_rl_dir;
// 	unsigned int	plyr_color;
// }	t_player;

// typedef struct s_ray
// {
// 	double	ray_angle;
// 	double	wall_x;
// 	double	wall_y;
// 	double	distance;
// 	int		is_hit_v;
// 	int		is_down;
// 	int		is_up;
// 	int		is_right;
// 	int		is_left;
// 	char	ray_dir;
// }	t_ray;

// typedef struct s_mlx
// {
// 	void			*mlx;
// 	void			*mlx_win;
// 	t_img			mlx_img;
// 	t_map			map;
// 	int				win_w;
// 	int				win_h;
// 	t_player		player;
// 	t_ray			ray;
// 	double			fov;
// 	double			scale;
// 	double			num_rays;
// 	unsigned int	map_color;
// 	t_leaks			*leak;
// 	t_texture		txt[4];
// }	t_mlx;

typedef struct s_raycast
{
	double	x_inter;
	double	y_inter;
	double	x_step;
	double	y_step;
	double	next_h_x;
	double	next_h_y;
	double	found_h_wall;
	double	found_v_wall;
	double	next_v_x;
	double	next_v_y;
	double	h_dist;
	double	v_dist;
	double	h_hit_x;
	double	h_hit_y;
	double	v_hit_x;
	double	v_hit_y;
}	t_raycast;

typedef struct s_wall
{
	int				i;
	double			wall_h;
	double			dist_proj;
	double			ray_angle;
	int				j;
	int				start;
	int				end;
	double			true_dist;
	int				offset_x;
	int				offset_y;
	unsigned int	texel_color;
}	t_wall;

/* parsing*/

// int				count_lines(char *argv[], t_mlx *mlx);
// char			**ft_parse(char *argv[], t_mlx *mlx);
// void			count_length(t_mlx *mlx);
// void			draw_map(t_mlx *mlx);
// void			get_player_coordinates(t_mlx *mlx);
// int				rgb2int(int r, int g, int b);

/*			init		*/
t_ray			init_ray(double ray_angle);
t_player		init_player(t_mlx *mlx);
t_mlx			*init_mlx(char *argv[]);

/*				Math		*/
double			dist_points(double x1, double y1, double x2, double y2);
double			normalize_angle(double angle);
double			get_player_angle(char c);
/*				keys			*/
int				key_press(int key, t_mlx *mlx);
void			move_forward(t_mlx *mlx);
void			move_backward(t_mlx *mlx);
void			move_left(t_mlx *mlx);
void			move_right(t_mlx *mlx);
void			rotate_right(t_mlx *mlx);
void			rotate_left(t_mlx *mlx);
int				ft_exit(t_mlx *mlx, int is_esc);
void			update(t_mlx *mlx);
int				rgb2int(int r, int g, int b);

/*				not specified yet		*/
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_pixel_color(t_texture *data, int x, int y);

/*			Draw minimap			*/
void			draw_map(t_mlx *mlx);
void			draw_square(t_mlx *mlx, int x, int y, int is_p);
int				is_wall(double x, double y, t_mlx *mlx);

/*				raycasting				*/
void			init_casting(t_mlx *mlx);
void			draw_rays(t_mlx *mlx);
void			cast_ray(t_mlx *mlx, t_ray *ray);
void			cast_vert_ray(t_mlx *mlx, t_ray *ray, t_raycast *rcst);
void			cast_horz_ray(t_mlx *mlx, t_ray *ray, t_raycast *rcst);
void			detect_distance(t_ray *ray, t_raycast *rcst);
void			define_vert_data(t_mlx *mlx, t_ray *ray, t_raycast *rcst);
void			define_horz_data(t_mlx *mlx, t_ray *ray, t_raycast *rcst);

/*				rendring walls			*/
void			start_walls(t_mlx *mlx);
void			get_ray_direction(t_ray *ray);
void			ceil_floor(t_mlx *mlx, t_wall *wall);

/*					Textures				*/
void			get_textures(t_mlx *mlx);
void			init_textures(t_mlx *mlx);
void			north_texture(t_mlx *mlx, t_wall *wall);
void			south_texture(t_mlx *mlx, t_wall *wall);
void			east_texture(t_mlx *mlx, t_wall *wall);
void			west_texture(t_mlx *mlx, t_wall *wall);

/*				free memory     */
void			leaks_removal(t_leaks **leaks, void *ptr);
void			free_leaks(t_leaks **garbage);
void			ft_free_mlx(t_mlx *mlx);
#endif
