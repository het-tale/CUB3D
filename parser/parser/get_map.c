/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:24:32 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/12 03:21:16 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	get_map(t_mlx *param, int fd, char *av)
{
	int		len;
	int		i;
	char	**map;

	i = 0;
	check_info(param, fd, av);
	param->map->width = 0;
	map = check_map(fd, av, param);
	len = count_lines(fd, av) - param->map->start;
	param->map->map = (char **)malloc(sizeof(char *) * (len + 1));
	leaks_removal(&param->leak, param->map->map);
	while (map[param->map->start])
	{
		if (map[param->map->start] == NULL)
			break ;
		if (check_errors(map[param->map->start], param) == 0)
			ft_error ("Error \n > in map \n");
		param->map->map[i] = map[param->map->start];
		i++;
		param->map->start++;
	}
	param->map->height = i;
	param->map->map[i] = NULL;
	if (param->map->c_plyr != 1)
		ft_error("Error \n > one plyr plllls \n");
}

int	check_wall_loop(t_mlx *param, int j, char *str, int i)
{
	while (str[j])
	{
		if (i == 0 && str[j] != '1' && str[j] != ' '
			&& str[j] != '\t' && str[j] != '\n')
			return (0);
		else if (*str != '1')
			return (0);
		else if (param->map->map[i + 1] == NULL && str[j] != '1'
			&& str[j] != ' ' && str[j] != '\t')
			return (0);
		else if (str[j + 2] == '\0' && str[j] != '1'
			&& str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	check_wall(t_mlx *param)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (param->map->map[i])
	{
		j = 0;
		str = skip_spaces(param->map->map[i]);
		if (*str == '\n')
			return (0);
		if (!check_wall_loop(param, j, str, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_elements_map_subloop(t_mlx *param, int *i, int *j, char p)
{
	if (param->map->map[*i][*j] == '0' || param->map->map[*i][*j] == p)
	{
		if (param->map->map[*i + 1][*j] == '\0'
			|| param->map->map[*i + 1][*j] == ' '
			|| param->map->map[*i + 1][*j] == '\t'
			|| param->map->map[*i + 1][*j] == '\n')
			return (0);
		else if (param->map->map[*i - 1][*j] == ' '
		|| param->map->map[*i - 1][*j] == '\t'
		|| param->map->map[*i - 1][*j] == '\n')
			return (0);
		else if (param->map->map[*i][*j + 1] == ' '
		|| param->map->map[*i][*j + 1] == '\t')
			return (0);
		else if (param->map->map[*i][*j - 1] == ' '
		|| param->map->map[*i][*j - 1] == '\t')
			return (0);
	}
	return (1);
}

int	check_elements_map_loop(t_mlx *param, int i, int j, char p)
{
	while (param->map->map[i])
	{
		j = 0;
		while (param->map->map[i][j] && param->map->map[i][j] != '\n')
		{
			if (check_elements_map_subloop(param, &i, &j, p) == 0)
				return (ft_error("Error \n > in map !!!!\n"));
			j++;
		}
		i++;
	}
	return (1);
}
