/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:07:12 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 10:37:38 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	init(t_param *param)
{
	param->textures.no = NULL;
	param->textures.so = NULL;
	param->textures.ea = NULL;
	param->textures.we = NULL;
	param->colors = malloc (sizeof(t_colors));
	param->map = malloc (sizeof(t_map));
	param->colors->c = NULL;
	param->colors->f = NULL;
	param->map->map = NULL;
	param->map->start = -1;
	param->map->c_plyr = 0;
}

void	pos_plyr(t_param *param)
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
				param->player.xpos = j;
				param->player.ypos = i;
				param->player.dir = param->map->map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_param	param;
	int		fd;

	if (ac != 2)
	{
		my_putstr("Error : Number of arguments\n");
		exit(1);
	}
	init(&param);
	fd = open(av[1], O_RDWR);
	get_map(&param, fd, av[1]);
	pos_plyr(&param);
	if (check_elements_map(&param) == 1)
		printf("Map Valid\n");
}
