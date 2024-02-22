/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:36 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 11:14:16 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_ctx	*init_main(char *name)
{
	t_ctx		*c;

	c = malloc(sizeof(t_ctx));
	if (!c)
		destroy(c, "Failed to alloc c!", 1);
	c->player = NULL;
	c->world = NULL;
	c->root = NULL;
	c->put_i = &mlx_put_image_to_window;
	c->des_i = &mlx_destroy_image;
	c->n_win = &mlx_new_window;
	c->mlx_ctx = mlx_init();
	c->max_idle = 4;
	init_map(c, name);
	c->height = get_height(c) * SIZE;
	c->width = get_width(c) * SIZE;
	if (!c->mlx_ctx)
		destroy(c, "Failed to create mlx instance!", 1);
	ft_printf("[DEBUG]		[%d x %d]\n", c->width, c->height);
	c->root = c->n_win(c->mlx_ctx, c->width, c->height + SIZE / 2, TITLE);
	if (!c->root)
		destroy(c, "Failed to create window!", 1);
	return (c);
}
