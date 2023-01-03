/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:28:43 by het-tale          #+#    #+#             */
/*   Updated: 2021/11/25 20:27:45 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	j = dstlen;
	if (dstsize == 0 || dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[i] && i < dstsize - dstlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dstlen + srclen);
}
