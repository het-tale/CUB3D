/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:48:55 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/08 15:35:13 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// int	get_pixel_color(t_texture *img, int x, int y)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
// 	return (*(unsigned int *)dst);
// }

unsigned int	get_pixel_color(t_texture *data, int x, int y)
{
	char			*dst;

	dst = data->t_addr + (y * data->ll + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	else if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
