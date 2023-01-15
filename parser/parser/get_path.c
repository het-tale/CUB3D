/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:57:08 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/15 18:38:34 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	count_lines(int fd, char *av)
{
	char	*str;
	int		len;

	len = 0;
	if (!check_extension(av, ".cub"))
		ft_error ("Error :\n>>Map file should have .cub\n");
	fd = open(av, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		ft_error ("Error :\n>>Empty file !\n");
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		len++;
	}
	free(str);
	close(fd);
	return (len);
}

char	**check_map(int fd, char *av, t_mlx *param)
{
	int		i;
	int		len;
	char	*line;
	char	**map;

	i = 0;
	len = count_lines(fd, av);
	map = (char **)malloc(sizeof(char *) * (len + 1));
	leaks_removal(&param->leak, map);
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free (line);
	map[i] = NULL;
	close (fd);
	return (map);
}
