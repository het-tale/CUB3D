/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:39:41 by het-tale          #+#    #+#             */
/*   Updated: 2023/01/12 03:43:32 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		write(2, "Usage : ./cub3d <filename>\n", 28);
		exit(EXIT_FAILURE);
	}
	mlx = init_mlx(argv);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_press, mlx);
	mlx_mouse_hook(mlx->mlx_win, mouse_movement, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_exit, mlx);
	mlx_loop(mlx->mlx);
	free_leaks(&mlx->leak);
	return (0);
}
