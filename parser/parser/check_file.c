/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:26:03 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 13:41:21 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_extension(char *argv, char *exten)
{
	int	len;

	if (argv && argv[0] == '.')
		return (0);
	len = ft_strlen(argv);
	if (len > 4 && ft_strncmp(ft_substr(argv, len - 4, len), exten, 4) == 0)
		return (1);
	return (0);
}

int	check_extension_tex(char *argv, char *exten, int size)
{
	char	*str;

	str = skip_spaces(argv);
	if (ft_strncmp(ft_substr(argv, size - 4, size), exten, 4) == 0 && size > 4)
		return (1);
	return (0);
}

// char	*remove_newline(char *line)
// {
// 	char	*res;
// 	int		len;

// 	len = ft_strlen(line);
// 	res = ft_substr(line, 0,len - 1);
// 	return (res);
// }

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
