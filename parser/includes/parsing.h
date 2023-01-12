/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:52:28 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/12 02:47:44 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 1

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		ll;
}	t_img;

typedef struct s_leaks
{
	void			*leak;
	struct s_leaks	*next;
}	t_leaks;

typedef struct s_texture
{
	char	*name;
	int		width;
	int		height;
	void	*t_image;
	char	*t_addr;
	int		bpp;
	int		ll;
	int		end;
}	t_texture;

typedef struct s_player
{
	double			x;
	double			y;
	char			direction;
	double			rot_speed;
	double			move_speed;
	double			rot_angle;
	double			turn_direction;
	double			walk_ud_dir;
	double			walk_rl_dir;
	unsigned int	plyr_color;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_x;
	double	wall_y;
	double	distance;
	int		is_hit_v;
	int		is_down;
	int		is_up;
	int		is_right;
	int		is_left;
	char	ray_dir;
}	t_ray;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		start;
	int		c_plyr;
	int		size;
}	t_map;

typedef struct s_colors
{
	int		ceiling[3];
	int		floor[3];
	char	*c;
	char	*f;
}	t_colors;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_img			mlx_img;
	t_map			*map;
	int				win_w;
	int				win_h;
	t_player		player;
	t_ray			ray;
	double			fov;
	double			scale;
	double			num_rays;
	unsigned int	map_color;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	t_leaks			*leak;
	t_texture		txt[4];
	t_colors		*colors;
}	t_mlx;

/*
============================== Libft ====================================
*/
int		ft_isalpha(int c);
int		ft_toupper(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_tolower(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	**ft_split(char const *s, char c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
/*
============================== GNL ====================================
*/

char	*get_next_line(int fd);
size_t	ft_strlenn(const char *s);
char	*ft_strdupp(char *s1);
int		ft_strchrr(char *s, int c);
char	*ft_strjoinn(char *s1, char *s2);
char	*get_line(char *s);
char	*get_after_newline(char *qarchala);

/*
============================== PARSER ====================================
*/

int		my_putstr(char *str);
int		ft_error(char *str);
char	*skip_spaces(char *line);
int		check_extension(char *argv, char *exten);
int		check_extension_tex(char *argv, char *exten, int size);
int		check_files_tex(char *tex);
int		count_lines(int fd, char *av);
char	**check_map(int fd, char *av, t_mlx *param);
int		check_errors(char *str, t_mlx *param);
void	get_map(t_mlx *param, int fd, char *av);
int		check_wall(t_mlx *param);
int		check_elements_map(t_mlx *param);
void	check_info(t_mlx *param, int fd, char *av);
int		get_rgb(char *str, int *rgb);
int		check_errors_rgb(const char *str);
void	init(t_mlx *param);
void	pos_plyr(t_mlx *param);
int		check_elements_map_loop(t_mlx *param, int i, int j, char p);

#endif