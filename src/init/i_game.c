/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:36 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 21:46:29 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	get_height(t_ctx *c)
{
	return (ft_strarraylen(c->map));
}

static int	get_width(t_ctx *c)
{
	return (ft_strlen(c->map[0]));
}

t_ctx	*init_main(void)
{
	t_ctx		*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		destroy(ctx, "Failed to alloc ctx!", 1);
	ctx->mlx_ctx = mlx_init();
	if (!ctx->mlx_ctx)
		destroy(ctx, "Failed to create mlx instance!", 1);
	ctx->map = load_map("./res/maps/map.ber");
	if (!ctx->map)
		destroy(ctx, "Failed to load map!", 1);
	ctx->height = get_height(ctx) * 32;
	ctx->width = (get_width(ctx) - 1) * 32;
	ft_printf("\n[DEBUG] %d x %d\n", ctx->width, ctx->height);
	ctx->root = mlx_new_window(ctx->mlx_ctx, ctx->width, ctx->height, TITLE);
	if (!ctx->root)
		destroy(ctx, "Failed to create window!", 1);
	ctx->game_running = 1;
	ctx->current_key = 0;
	ctx->put_i = &mlx_put_image_to_window;
	ctx->des_i = &mlx_destroy_image;
	return (ctx);
}
