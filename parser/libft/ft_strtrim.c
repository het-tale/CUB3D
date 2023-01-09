/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:03:44 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/08 00:00:16 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]))
	{
		i++;
		if (i > len)
			break ;
	}
	while (ft_strchr(set, s1[len - 1]))
	{
		len--;
		if (len == 0)
			break ;
	}
	if (len < i)
		return (ft_strdup(""));
	return (ft_substr(s1, i, len - i));
}