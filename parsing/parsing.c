/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:43:34 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/06 02:22:33 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	count_lines(char *argv[], t_mlx *mlx)
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
		leaks_removal(&mlx->leak, line);
	}
	leaks_removal(&mlx->leak, line);
	return (lines);
}

char	**ft_parse(char *argv[], t_mlx *mlx)
{
	int		fd;
	int		count;
	char	*line;
	char	**map;
	int		i;

	line = "";
	count = count_lines(argv, mlx);
	fd = open(argv[1], O_RDONLY);
	map = malloc((count + 1) * sizeof(char *));
	leaks_removal(&mlx->leak, map);
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
		leaks_removal(&mlx->leak, map[i]);
		leaks_removal(&mlx->leak, line);
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

void	get_player_coordinates(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'N' || mlx->map[i][j] == 'S' || mlx->map[i][j] == 'E' || mlx->map[i][j] == 'W')
			{
				mlx->player.pos[0] = j;
				mlx->player.pos[1] = i;
				mlx->player.direction = mlx->map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
}

int	rgb2int(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

//1 * 180 = pi
//x rad = x deg * (pi / 180)
//x deg = x rad * (180 / pi)