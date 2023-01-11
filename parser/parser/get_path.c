/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:57:08 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/11 21:24:01 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	count_lines(int fd, char *av)
{
	char	*str;
	int		len;

	len = 0;
	if (!check_extension(av, ".cub"))
		ft_error ("Error : map file should have .cub\n");
	fd = open(av, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		ft_error ("Error : Empty file ! \n");
	free (str);
	while (str != NULL)
	{
		str = get_next_line(fd);
		free(str);
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
	free(line);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		line = get_next_line(fd);
		free(line);
		i++;
	}
	free (line);
	map[i] = NULL;
	close (fd);
	return (map);
}
