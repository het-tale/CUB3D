/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:18:18 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/15 18:37:54 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	get_line_info(char *str, char *s2, int size, char **tex)
{
	char	*line;

	if (ft_strncmp(str, s2, size) == 0)
	{
		if (*tex)
			return (ft_error("Error\n>> Element duplicate in map \n"));
		else
		{
			line = ft_substr(str, size, ft_strlen(str) - size - 1);
			*tex = ft_strdup(skip_spaces(line));
			free(line);
			return (1);
		}
	}
	return (0);
}

int	check_for_textures(char *str, t_mlx *param)
{
	if (get_line_info(str, "NO ", 3, &param->txt[0].name) == 1)
		return (1);
	else if (get_line_info(str, "SO ", 3, &param->txt[1].name) == 1)
		return (1);
	else if (get_line_info(str, "EA ", 3, &param->txt[2].name) == 1)
		return (1);
	else if (get_line_info(str, "WE ", 3, &param->txt[3].name) == 1)
		return (1);
	return (0);
}

int	check_for_colors(char *str, t_mlx *param)
{
	if (get_line_info(str, "F ", 2, &param->colors->f) == 1)
		return (1);
	else if (get_line_info(str, "C ", 2, &param->colors->c) == 1)
		return (1);
	else if (*str == '\n')
		return (1);
	return (0);
}

int	treat_textures(char **map, t_mlx *param, int i)
{
	char	*str;

	while (map[i])
	{
		str = skip_spaces(map[i]);
		free(map[i]);
		if (check_for_textures(str, param) || check_for_colors(str, param))
		{
			i++;
			continue ;
		}
		else
		{
			param->map->start = i;
			return (1);
		}
	}
	return (0);
}

void	check_info(t_mlx *param, int fd, char *av)
{
	char	**map;
	int		i;

	i = 0;
	map = check_map(fd, av, param);
	if (treat_textures(map, param, i) == 0)
		ft_error("Error \n > In map\n");
	if (param->map->start == -1)
		ft_error("Error\n > Empty map !!");
	if (!param->colors->c || !param->colors->f || !param->txt[2].name
		|| !param->txt[0].name || !param->txt[1].name || !param->txt[3].name)
		ft_error("Error \n >  Pooooor map !!");
	if (get_rgb(param->colors->f, param->colors->floor) == 0
		|| get_rgb(param->colors->c, param->colors->ceiling) == 0)
		ft_error("Error\n > Error in colors !!");
	if (check_files_tex(param->txt[2].name) == 2
		|| check_files_tex(param->txt[0].name) == 2
		|| check_files_tex(param->txt[3].name) == 2
		|| check_files_tex(param->txt[1].name) == 2)
		ft_error("Error \n > file not exist or Permission denied");
	if (check_files_tex(param->txt[0].name) == 0
		|| check_files_tex(param->txt[2].name) == 0
		|| check_files_tex(param->txt[3].name) == 0
		|| check_files_tex(param->txt[1].name) == 0)
		ft_error("Error \n >  Exetension textures ");
}
