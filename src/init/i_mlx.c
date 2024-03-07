/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:58:58 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 18:35:36 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_mlx(t_ctx *c, char *name)
{
	int	ui_offset;

	ui_offset = SIZE + (SIZE / 2);
	c->win_title = ft_strjoin(TITLE, name);
	if (!c->win_title)
		destroy(c, "Failed to join and make title!", true);
	c->des_i = &mlx_destroy_image;
	c->mlx_ctx = mlx_init();
	if (!c->mlx_ctx)
		destroy(c, "Failed to create mlx instance!", true);
	c->height = c->map->rows * SIZE;
	c->width = c->map->columns * SIZE;
	if (c->width < (SIZE * 15))
		ui_offset = SIZE + (SIZE * 2);
	c->buffer = mlx_new_image(c->mlx_ctx, c->width, c->height + ui_offset);
	ft_printf("["BBLU"MLX"RESET"]		Created mlx instance\n");
	ft_printf("["BBLU"MLX"RESET"]		%d x %d\n", c->width, c->height);
	c->root = mlx_new_window(c->mlx_ctx, c->width,
			c->height + ui_offset, c->win_title);
	if (!c->root)
		destroy(c, "Failed to create window!", true);
}
