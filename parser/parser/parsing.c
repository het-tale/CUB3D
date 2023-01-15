/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:07:12 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/12 03:21:39 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	init(t_mlx *param)
{
	param->txt[0].name = NULL;
	param->txt[1].name = NULL;
	param->txt[2].name = NULL;
	param->txt[3].name = NULL;
	param->colors = malloc (sizeof(t_colors));
	leaks_removal(&param->leak, param->colors);
	param->map = malloc (sizeof(t_map));
	leaks_removal(&param->leak, param->map);
	param->colors->c = NULL;
	param->colors->f = NULL;
	param->map->map = NULL;
	param->map->start = -1;
	param->map->c_plyr = 0;
}

int	check_elements_map(t_mlx *param)
{
	int		i;
	int		j;
	char	p;

	i = 0;
	j = 0;
	p = param->player.direction;
	if (!check_wall(param))
		ft_error("Error \n > in wall map !");
	return (check_elements_map_loop(param, i, j, p));
}

void	pos_plyr(t_mlx *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map->map[i])
	{
		j = 0;
		while (param->map->map[i][j])
		{
			if (param->map->map[i][j] == 'N' || param->map->map[i][j] == 'S'
				|| param->map->map[i][j] == 'E' || param->map->map[i][j] == 'W')
			{
				param->player.x = j;
				param->player.y = i;
				param->player.direction = param->map->map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
}
