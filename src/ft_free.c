/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:10:21 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/05 03:11:06 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	leaks_removal(t_leaks **leaks, void *ptr)
{
	t_leaks	*garbage;

	garbage = malloc(sizeof(t_leaks));
	garbage->leak = ptr;
	garbage->next = *(leaks);
	*leaks = garbage;
}

void	free_leaks(t_leaks **garbage)
{
	t_leaks	*trash;

	trash = *garbage;
	while (trash)
	{
		free(*garbage);
		trash = trash->next;
		*garbage = trash;
	}
}
