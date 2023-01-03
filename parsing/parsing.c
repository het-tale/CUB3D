/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:43:34 by het-tale          #+#    #+#             */
/*   Updated: 2022/12/31 09:34:59 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	count_lines(char *argv[])
{
	int		lines;
	char	*line;
	int		fd;

	line = "";
	lines = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lines++;
	}
	return (lines);
}

char	**ft_parse(char *argv[])
{
	int		fd;
	int		count;
	char	*line;
	char	**map;
	int		i;

	line = "";
	count = count_lines(argv);
	fd = open(argv[1], O_RDONLY);
	map = malloc((count + 1) * sizeof(char *));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			map[i] = NULL;
			break ;
		}
		map[i] = ft_strdup(line);
		i++;
	}
	return (map);
}

void	count_length(t_mlx *mlx)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	mlx->map_w = 0;
	while (mlx->map[++i])
	{
		count = ft_strlen(mlx->map[i]);
		if (mlx->map[i][count - 1] == '\n')
			count--;
		if (mlx->map_w < count)
			mlx->map_w = count;
	}
}

//1 * 180 = pi
//x rad = x deg * (pi / 180)
//x deg = x rad * (180 / pi)