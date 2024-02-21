/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 17:54:58 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int arg_n, char **arg_a)
{
	t_ctx	*ctx;
	char	*name;	

	name = "map.ber";
	if (arg_n == 2)
		name = arg_a[1];
	ctx = init_main(name);
	init_player(ctx);
	init_world(ctx);
	mlx_loop_hook(ctx->mlx_ctx, update, ctx);
	mlx_hook(ctx->root, KeyPress, KeyPressMask, key_press_handler, ctx);
	mlx_hook(ctx->root, KeyRelease, KeyReleaseMask, key_release_handler, ctx);
	mlx_hook(ctx->root, DestroyNotify, 0, close_program, ctx);
	mlx_loop(ctx->mlx_ctx);
	destroy(ctx, "Goodbye!", 0);
	return (0);
}
