/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/20 16:13:14 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	t_ctx		*ctx;

	ft_printf(GRN"\n[DEBUG]	This is so_long!\n"RESET);
	ctx = init_main();
	init_player(ctx);
	init_world(ctx);
	mlx_loop_hook(ctx->mlx_ctx, update, ctx);
	mlx_hook(ctx->root, KeyPress, KeyPressMask, key_press_handler, ctx);
	mlx_hook(ctx->root, KeyRelease, KeyReleaseMask, key_release_handler, ctx);
	mlx_hook(ctx->root, DestroyNotify, 0, close_program, ctx);
	mlx_loop(ctx->mlx_ctx);
	destroy(ctx, "	Goodbye!", 0);
	return (0);
}
