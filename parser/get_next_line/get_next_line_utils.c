/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:07:15 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/07 23:55:04 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

size_t	ft_strlenn(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdupp(char *s1)
{
	unsigned int	len;
	unsigned int	i;
	char			*p;

	i = 0;
	len = ft_strlenn(s1);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (p == 0)
		return (NULL);
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strchrr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*rest;
	size_t	count;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdupp(s2));
	if (!s2)
		return (ft_strdupp(s1));
	count = ft_strlenn(s1) + ft_strlenn(s2) + 1;
	rest = (char *)malloc(sizeof(char) * count);
	if (!rest)
		return (NULL);
	while (s1[i] != '\0')
		rest[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		rest[j++] = s2[i++];
	rest[j] = '\0';
	free(s1);
	return (rest);
}
