/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:36 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 18:04:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_ctx	*init_main(char *name)
{
	t_ctx		*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		destroy(ctx, "Failed to alloc ctx!", 1);
	ctx->player = NULL;
	ctx->world = NULL;
	ctx->root = NULL;
	ctx->game_running = 1;
	ctx->current_key = 0;
	ctx->put_i = &mlx_put_image_to_window;
	ctx->des_i = &mlx_destroy_image;
	ctx->mlx_ctx = mlx_init();
	init_map(ctx, name);
	ctx->height = get_height(ctx) * SIZE;
	ctx->width = get_width(ctx) * SIZE;
	if (!ctx->mlx_ctx)
		destroy(ctx, "Failed to create mlx instance!", 1);
	ft_printf("[DEBUG]		[%d x %d]\n", ctx->width, ctx->height);
	ctx->root = mlx_new_window(ctx->mlx_ctx, ctx->width, ctx->height + SIZE / 2, TITLE);
	if (!ctx->root)
		destroy(ctx, "Failed to create window!", 1);
	return (ctx);
}
