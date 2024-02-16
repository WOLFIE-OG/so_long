/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:36 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 14:50:06 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_ctx	*init_main(void)
{
	t_ctx		*ctx;

	ctx = (t_ctx *)malloc(sizeof(t_ctx));
	ctx->mlx_ctx = mlx_init();
	ctx->width = WIDTH;
	ctx->height = HEIGHT;
	ctx->root = mlx_new_window(ctx->mlx_ctx, ctx->width, ctx->height, TITLE);
	ctx->game_running = 1;
	ctx->put_i = &mlx_put_image_to_window;
	ctx->des_i = &mlx_destroy_image;
	return (ctx);
}
