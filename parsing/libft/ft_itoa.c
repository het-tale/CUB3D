/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:18:57 by het-tale          #+#    #+#             */
/*   Updated: 2021/11/21 21:16:13 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	intlen(int n)
{
	unsigned int	i;
	int				j;

	j = 0;
	if (n < 0)
	{
		j++;
		i = (unsigned int) n * -1;
	}
	else
		i = (unsigned int) n;
	while (i != 0)
	{
		i /= 10;
		j++;
	}
	return (j);
}

static	void	fill_string(unsigned int nbr, int nb, int len, char *str)
{
	while (nbr != 0)
	{
		nb = nbr % 10;
		nbr /= 10;
		str[len - 1] = nb + 48;
		len--;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*str;
	int				len;
	int				i;
	int				nb;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	nbr = 0;
	len = intlen(n);
	nb = n;
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (0);
	str[len] = 0;
	if (n < 0)
	{
		str[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	fill_string(nbr, nb, len, str);
	return (str);
}
