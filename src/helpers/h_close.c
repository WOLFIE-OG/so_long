/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_close.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:37 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 14:05:52 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	close_program(t_ctx *ctx)
{
	mlx_clear_window(ctx->mlx_ctx, ctx->root);
	ctx->game_running = 0;
	mlx_loop_end(ctx->mlx_ctx);
	return (0);
}
