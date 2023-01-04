/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:48:55 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/04 11:12:48 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ddaline(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	int		dx;
	int		dy;
	int		steps;
	int		i;
	float	xinc;
	float	yinc;
	float	x;
	float	y;

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	if (dx > dy)
		steps = dx;
	else
		steps = dy;
	xinc = (x2 - x1) / (float) steps;
	yinc = (y2 - y1) / (float) steps;
	x = x1;
	y = y1;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(&mlx->mlx_img, mlx->scale * x, mlx->scale * y, 0xff0000);
		x += xinc;
		y += yinc;
		i++;
	}
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}
