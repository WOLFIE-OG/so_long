/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:53:45 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 22:36:57 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_sprites(t_ctx *ctx)
{
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->idle);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->left_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->left);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->right_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->right);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up);
}

void	free_sprites_extra(t_ctx *ctx)
{
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_left_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_left);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_right_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_right);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_left_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_left);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_right_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_right);
}

void	free_sprites_extra_extra(t_ctx *ctx)
{
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->bottom_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->bottom);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->top_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->top);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->side_l_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->side_l);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->side_r_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->side_r);
}
