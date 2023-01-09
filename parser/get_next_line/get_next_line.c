/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 02:48:08 by aheddak           #+#    #+#             */
/*   Updated: 2023/01/09 11:15:05 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*get_line(char *s)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (s[0] == '\0')
		return (NULL);
	while (s[l] && s[l] != '\n')
		l++;
	if (s[l] == '\n')
		l++;
	str = (char *)malloc(sizeof(char) * (l + 1));
	while (s[i] != '\0')
	{
		str[i] = s[i];
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_after_newline(char *qarchala)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!qarchala)
		return (NULL);
	while (qarchala[i] && qarchala[i] != '\n')
		i++;
	if (qarchala[i] == '\n')
		i++;
	if (i == (int)ft_strlenn(qarchala))
	{
		free(qarchala);
		return (NULL);
	}
	line = (char *)malloc((ft_strlenn(qarchala) - i + 1) * sizeof(char));
	while (qarchala[i] != '\0')
		line[j++] = qarchala[i++];
	line[j] = '\0';
	free(qarchala);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	int			l;
	static char	*buff;

	l = 1;
	if (fd < 0)
		return (NULL);
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (l > 0 && ft_strchrr(buff, '\n') == 0)
	{
		l = read(fd, str, BUFFER_SIZE);
		if (l < 0)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		str[l] = '\0';
		buff = ft_strjoinn(buff, str);
	}
	free(str);
	line = get_line(buff);
	buff = get_after_newline(buff);
	return (line);
}
