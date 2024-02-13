/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/13 16:08:11 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void *mlx;
void *win1;
void *win2;

int gere_mouse(int x, int y, int button, void *toto)
{
	(void)x;
	(void)y;
	(void)button;
	(void)toto;
	ft_printf("Mouse event - new win\n");
	mlx_destroy_window(mlx, win1);
	win1 = mlx_new_window(mlx, random() % 500, random() % 500, "new win");
	mlx_mouse_hook(win1, gere_mouse, 0);
	return (0);
}


int	main(void)
{
	ft_printf(GRN"This is so_long!\n"RESET);
	mlx = mlx_init();
	win1 = mlx_new_window(mlx, 300,300, "win1");
	win2 = mlx_new_window(mlx, 600,600, "win2");
	mlx_mouse_hook(win1, gere_mouse, 0);
	mlx_mouse_hook(win2, gere_mouse, 0);
	mlx_loop(mlx);
	return (0);
}