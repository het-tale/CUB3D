/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:38:40 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 11:15:05 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	a;

	if (n < 0)
	{
		a = (unsigned int ) -n;
		write (fd, "-", 1);
	}
	else
		a = (unsigned int) n;
	if (a >= 10)
	{
		c = (a % 10) + '0';
		ft_putnbr_fd(a / 10, fd);
		write (fd, &c, 1);
	}
	if (a < 10)
	{
		c = a + '0';
		write (fd, &c, 1);
	}
}
