/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:52:28 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 10:25:18 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 1

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
}				t_textures;

typedef struct s_colors
{
	int		ceiling[3];
	int		floor[3];
	char	*c;
	char	*f;
}				t_colors;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		start;
	int		c_plyr;
	int		size;
}			t_map;

typedef struct s_plyr
{
	int		xpos;
	int		ypos;
	char	dir;
}				t_plyr;

typedef struct s_param
{
	t_map		*map;
	t_plyr		player;
	t_textures	textures;
	t_colors	*colors;
}		t_param;

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
void	*ft_memcpy( void *dst, const void *src, size_t n);
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
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
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
char	**check_map(int fd, char *av);
int		check_errors(char *str, t_param *param);
void	get_map(t_param *param, int fd, char *av);
int		check_wall(t_param *param);
int		check_elements_map(t_param *param);
void	check_info(t_param *param, int fd, char *av);
int		get_rgb(char *str, int *rgb);
int		check_errors_rgb(const char *str);

#endif