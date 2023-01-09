/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:57:08 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 08:14:54 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

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
	while (str != NULL)
	{
		str = get_next_line(fd);
		len++;
	}
	close(fd);
	return (len);
}

char	**check_map(int fd, char *av)
{
	int		i;
	int		len;
	char	*line;
	char	**map;

	i = 0;
	len = count_lines(fd, av);
	map = (char **)malloc(sizeof(char *) * (len + 1));
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close (fd);
	return (map);
}
