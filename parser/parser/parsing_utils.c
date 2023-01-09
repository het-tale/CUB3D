/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:25:10 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 11:15:05 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	my_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (1);
}

int	ft_error(char *str)
{
	my_putstr(str);
	exit(1);
}

char	*skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line)
	{
		if (!(line[i] == ' ' || line[i] == '\t'))
			break ;
		i++;
	}
	return (line + i);
}
