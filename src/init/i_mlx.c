/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:58:58 by otodd             #+#    #+#             */
/*   Updated: 2024/02/26 19:52:40 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_mlx(t_ctx *c, char *name)
{
	c->win_title = ft_strjoin(TITLE, name);
	if (!c->win_title)
		destroy(c, "Failed to join and make title!", 1);
	c->des_i = &mlx_destroy_image;
	c->n_win = &mlx_new_window;
	c->mlx_ctx = mlx_init();
	if (!c->mlx_ctx)
		destroy(c, "Failed to create mlx instance!", 1);
	c->height = get_height(c) * SIZE;
	c->width = get_width(c) * SIZE;
	c->buffer = mlx_new_image(c->mlx_ctx, c->width, c->height);
	ft_printf("["BBLU"MLX"RESET"]		Created mlx instance\n");
	c->root = c->n_win(c->mlx_ctx, c->width,
			c->height + SIZE / 2, c->win_title);
	if (!c->root)
		destroy(c, "Failed to create window!", 1);
}
