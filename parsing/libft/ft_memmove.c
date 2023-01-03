/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:16:11 by het-tale          #+#    #+#             */
/*   Updated: 2021/11/25 20:27:37 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t	i;

	i = 0;
	source = (char *)src;
	dest = (char *)dst;
	if (!dest && !source)
		return (NULL);
	if (dest > source)
	{
		while (i < len)
		{
			dest[len - i - 1] = source[len - i - 1];
			i++;
		}
	}
	else
		ft_memcpy(dest, source, len);
	return (dest);
}
