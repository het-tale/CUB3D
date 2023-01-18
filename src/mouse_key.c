/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:27:47 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/18 20:28:09 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	mouse_movement(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == 1)
		rotate_left(mlx);
	else if (key == 2)
		rotate_right(mlx);
	update(mlx);
	return (0);
}
