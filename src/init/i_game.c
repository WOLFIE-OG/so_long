/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:36 by otodd             #+#    #+#             */
/*   Updated: 2024/02/20 17:45:00 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	get_height(t_ctx *c)
{
	return (ft_strarraylen(c->map->data));
}

static int	get_width(t_ctx *c)
{
	return (ft_strlen(c->map->data[0]));
}

static void	init_map(t_ctx *ctx)
{
	ctx->map = malloc(sizeof(t_map));
	ctx->map->data = load_map("./res/maps/big.ber");
	if (!ctx->map)
		destroy(ctx, "Failed to load map!", 1);
	ctx->map->rows = get_height(ctx);
	ctx->map->columns = get_width(ctx);
}

t_ctx	*init_main(void)
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
	init_map(ctx);
	ctx->start_pos = malloc(sizeof(t_vector2));
	if (!ctx->start_pos)
		destroy(ctx, "Failed to alloc pos!", 1);
	ctx->height = get_height(ctx) * 32;
	ctx->width = (get_width(ctx) - 1) * 32;
	if (!ctx->mlx_ctx)
		destroy(ctx, "Failed to create mlx instance!", 1);
	ft_printf("\n[DEBUG] %d x %d\n", ctx->width, ctx->height);
	ctx->root = mlx_new_window(ctx->mlx_ctx, ctx->width, ctx->height, TITLE);
	if (!ctx->root)
		destroy(ctx, "Failed to create window!", 1);
	return (ctx);
}
