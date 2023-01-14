/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:39:41 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/14 16:02:07 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	(void)mlx;
	(void)argv;
	if (argc != 2)
	{
		write(2, "Usage : ./cub3d <filename>\n", 28);
		exit(EXIT_FAILURE);
	}
	mlx = init_mlx(argv);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_exit, mlx);
	mlx_mouse_hook(mlx->mlx_win, mouse_movement, mlx);
	mlx_loop(mlx->mlx);
	free_leaks(&mlx->leak);
	return (0);
}
