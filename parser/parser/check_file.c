/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:26:03 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/12 00:45:05 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_extension(char *argv, char *exten)
{
	char	*res;
	int		len;

	if (argv && argv[0] == '.')
		return (0);
	len = ft_strlen(argv);
	res = ft_substr(argv, len - 4, len);
	if (len > 4 && ft_strncmp(res, exten, 4) == 0)
	{
		free(res);
		return (1);
	}
	return (0);
}

int	check_extension_tex(char *argv, char *exten, int size)
{
	char	*res;

	res = ft_substr(argv, size - 4, size);
	if (ft_strncmp(res, exten, 4) == 0 && size > 4)
	{
		free(res);
		return (1);
	}
	return (0);
}

int	check_files_tex(char *tex)
{
	int		len;
	int		i;
	int		tmp;

	len = 0;
	i = 0;
	while (tex[len])
		len++;
	tmp = len;
	while (i < len)
	{
		if (tex[len - 2] != '\t' && tex[len - 2] != ' ')
			break ;
		i++;
		len--;
	}
	if (check_extension_tex(tex, ".xpm", tmp - i))
	{
		if (open(tex, O_RDONLY) < 0)
			return (2);
	}
	else
		return (0);
	return (1);
}

int	check_errors(char *str, t_mlx *param)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i > param->map->width)
		param->map->width = i;
	line = skip_spaces(str);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			param->map->c_plyr++;
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
