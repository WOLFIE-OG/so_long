/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_sprites.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:53:45 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 16:10:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_sprites(t_ctx *ctx)
{
	if (ctx->player->sprites->down_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_alt);
	if (ctx->player->sprites->down)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down);
	if (ctx->player->sprites->idle)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->idle);
	if (ctx->player->sprites->left_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->left_alt);
	if (ctx->player->sprites->left)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->left);
	if (ctx->player->sprites->right_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->right_alt);
	if (ctx->player->sprites->right)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->right);
	if (ctx->player->sprites->up_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_alt);
	if (ctx->player->sprites->up)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up);
}

void	free_sprites_extra(t_ctx *ctx)
{
	if (ctx->player->sprites->down_left_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_left_alt);
	if (ctx->player->sprites->down_left)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_left);
	if (ctx->player->sprites->down_right_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_right_alt);
	if (ctx->player->sprites->down_right)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_right);
	if (ctx->player->sprites->up_left_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_left_alt);
	if (ctx->player->sprites->up_left)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_left);
	if (ctx->player->sprites->up_right_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_right_alt);
	if (ctx->player->sprites->up_right)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_right);
}

void	free_sprites_extra_extra(t_ctx *ctx)
{
	if (ctx->player->sprites->bottom_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->bottom_alt);
	if (ctx->player->sprites->bottom)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->bottom);
	if (ctx->player->sprites->top_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->top_alt);
	if (ctx->player->sprites->top)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->top);
	if (ctx->player->sprites->side_l_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->side_l_alt);
	if (ctx->player->sprites->side_l)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->side_l);
	if (ctx->player->sprites->side_r_alt)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->side_r_alt);
	if (ctx->player->sprites->side_r)
		ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->side_r);
}

void	free_world_sprites(t_ctx *ctx)
{
	if (ctx->world->sprites->wall)
		ctx->des_i(ctx->mlx_ctx, ctx->world->sprites->wall);
	if (ctx->world->sprites->coin)
		ctx->des_i(ctx->mlx_ctx, ctx->world->sprites->coin);
	if (ctx->world->sprites->exit)
		ctx->des_i(ctx->mlx_ctx, ctx->world->sprites->exit);
	if (ctx->world->sprites->spawn)
		ctx->des_i(ctx->mlx_ctx, ctx->world->sprites->spawn);
}
