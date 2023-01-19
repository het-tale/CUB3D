/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:33:58 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/19 01:23:29 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_errors_rgb(const char *str)
{
	int					c;
	unsigned long		res;

	c = 0;
	res = 0;
	while (str[c] == '\t' || str[c] == ' ')
		c++;
	if (str[c] == '\0')
		return (0);
	if (str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (str[c] - '0') + (res * 10);
		if (res > 255)
			return (0);
		c++;
	}
	if (str[c])
	{
		if (str[c] == '\n')
			return (1);
		return (0);
	}
	return (1);
}

int	check_rgb_string(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	get_rgb(char *str, int *rgb)
{
	char	**split;
	int		i;

	if (!check_rgb_string(str))
		return (0);
	split = ft_split(str, ',');
	if (split[3] != NULL)
		return (0);
	i = 0;
	while (split[i])
	{
		if (check_errors_rgb(split[i]) == 0)
			return (0);
		rgb[i] = ft_atoi(split[i]);
		free (split[i]);
		i++;
	}
	free(split[i]);
	return (1);
}
