/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:41:57 by het-tale          #+#    #+#             */
/*   Updated: 2021/11/23 19:41:41 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	if (c == '\0')
		return ((char *)(str + len));
	while (i <= len)
	{
		if (str[len - i] == (char)c)
			return ((char *)(str + len - i));
		i++;
	}
	return (0);
}
