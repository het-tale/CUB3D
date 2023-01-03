/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:39:41 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/03 08:31:50 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		int t = write(2, "Usage : ./cub3d <filename>\n", 28);
		(void)t;
		exit(EXIT_FAILURE);
	}
	t_mlx	*mlx;

	mlx = init_mlx(argv);
	mlx_hook(mlx->mlx_win, 2, 1L<<0, key_press, mlx);
	mlx_hook(mlx->mlx_win, 3, 1L<<1, key_released, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_exit, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}