/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:18:18 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 13:39:47 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	get_line_info(char *str, char *s2, int size, char **tex)
{
	if (ft_strncmp(str, s2, size) == 0)
	{
		if (*tex)
			return (ft_error("Error : Duplicate \n"));
		else
		{
			*tex = ft_strdup(ft_substr(str, size, ft_strlen(str) - size - 1));
			// printf("tex---> %s\n", *tex);
			return (1);
		}
	}
	return (0);
}

int	treat_textures(char **map, t_mlx *param, int i)
{
	char	*str;

	while (map[i])
	{
		str = skip_spaces(map[i]);
		if (get_line_info(str, "NO ", 3, &param->txt[0].name) == 1)
		{
			i++;
			continue ;
		}
		else if (get_line_info(str, "SO ", 3, &param->txt[1].name) == 1)
		{
			i++;
			continue ;
		}
		else if (get_line_info(str, "WE ", 3, &param->txt[3].name) == 1)
		{
			i++;
			continue ;
		}
		else if (get_line_info(str, "EA ", 3, &param->txt[2].name) == 1)
		{
			i++;
			continue ;
		}
		else if (get_line_info(str, "F ", 2, &param->colors->f) == 1)
		{
			i++;
			continue ;
		}
		else if (get_line_info(str, "C ", 2, &param->colors->c) == 1)
		{
			i++;
			continue ;
		}
		else if (*str == '\n')
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
	map = check_map(fd, av);
	if (treat_textures(map, param, i) == 0)
		ft_error("Error : Duplicate\n");
	if (param->map->start == -1)
		ft_error("Error : Empty map !!");
	if (!param->colors->c || !param->colors->f || !param->txt[2].name
		|| !param->txt[0].name || !param->txt[1].name || !param->txt[3].name)
		ft_error("Error : Pooooor map !!");
	if (get_rgb(param->colors->f, param->colors->floor) == 0
		|| get_rgb(param->colors->c, param->colors->ceiling) == 0)
		ft_error("Error : Error in colors !!");
	if (check_files_tex(param->txt[2].name) == 2
		|| check_files_tex(param->txt[0].name) == 2
		|| check_files_tex(param->txt[3].name) == 2
		|| check_files_tex(param->txt[1].name) == 2)
		ft_error("Error : file not exist or Permission denied");
	if (check_files_tex(param->txt[0].name) == 0
		|| check_files_tex(param->txt[2].name) == 0
		|| check_files_tex(param->txt[3].name) == 0
		|| check_files_tex(param->txt[1].name) == 0)
		ft_error("Error : Exetension textures ");
}
