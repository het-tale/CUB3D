/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:08:10 by het-tale          #+#    #+#             */
/*   Updated: 2021/11/26 00:22:28 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	littlelen;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	else
	{
		littlelen = ft_strlen(little);
		while (i < len && big[i] != '\0')
		{
			if (i + littlelen <= len)
			{
				if (little[0] == big[i]
					&& ft_strncmp(big + i, little, littlelen) == 0)
					return ((char *)big + i);
			}
			i++;
		}	
	}
	return (0);
}
