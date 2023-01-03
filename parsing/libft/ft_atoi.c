/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:03:17 by het-tale          #+#    #+#             */
/*   Updated: 2021/11/25 20:42:38 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_maxcondition(int d)
{
	if (d < 0)
		return (0);
	else
		return (-1);
}

static	int	ft_isspace(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				d;
	unsigned long	res;

	i = 0;
	d = 1;
	res = 0;
	i = ft_isspace(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			d = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		if (res > 9223372036854775807)
			return (ft_maxcondition(d));
		i++;
	}
	return ((int)res * d);
}
