/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:15:05 by het-tale          #+#    #+#             */
/*   Updated: 2021/11/26 01:50:16 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)x;
		i++;
	}
	return (str);
}
