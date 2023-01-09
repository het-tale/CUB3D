/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:18:18 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 10:32:01 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	get_line_info(char *str, char *s2, int size, char **tex)
{
	if (ft_strncmp(str, s2, size) == 0)
	{
		if (*tex)
			return (ft_error("Error : Duplicate \n"));
		else
		{	
			*tex = ft_strdup(ft_substr(str, size, ft_strlen(str)));
			return (1);
		}
	}
	return (0);
}

int	treat_textures(char **map, t_param *param, int i)
{
	char	*str;

	while (map[i])
	{
		str = skip_spaces(map[i]);
		if (get_line_info(str, "NO ", 3, &param->textures.no) == 1)
		{
			i++;
			continue ;
		}
		else if (get_line_info(str, "SO ", 3, &param->textures.so) == 1)
		{
			i++;
			continue ;
		}
		else if (get_line_info(str, "WE ", 3, &param->textures.we) == 1)
		{
			i++;
			continue ;
		}
		else if (get_line_info(str, "EA ", 3, &param->textures.ea) == 1)
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

void	check_info(t_param *param, int fd, char *av)
{
	char	**map;
	int		i;

	i = 0;
	map = check_map(fd, av);
	if (treat_textures(map, param, i) == 0)
		ft_error("Error : Duplicate\n");
	if (get_rgb(param->colors->f, param->colors->floor) == 0
		|| get_rgb(param->colors->c, param->colors->ceiling) == 0)
		ft_error("Error : Error in colors !!");
	if (!param->colors->c || !param->colors->f || !param->textures.ea
		|| !param->textures.no || !param->textures.so || !param->textures.we)
		ft_error("Error : Pooooor map !!");
	if (param->map->start == -1)
		ft_error("Error : Empty map !!");
	// if (check_files_tex(param->textures.ea) == 2
	// 	|| check_files_tex(param->textures.no) == 2
	// 	|| check_files_tex(param->textures.we) == 2
	// 	|| check_files_tex(param->textures.so) == 2)
	// 	ft_error("Error : file not exist or Permission denied");
	if (check_files_tex(param->textures.no) == 0
		|| check_files_tex(param->textures.ea) == 0
		|| check_files_tex(param->textures.we) == 0
		|| check_files_tex(param->textures.so) == 0)
		ft_error("Error : Exetension textures ");
}
