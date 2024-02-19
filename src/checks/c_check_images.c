/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:18:23 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 21:46:35 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_sprites(t_ctx *ctx)
{
	if (ctx && ctx->player && ctx->player->sprites)
	{
		if (!ctx->player->sprites->down_alt)
			destroy(ctx, "down_alt.xpm not found!", 1);
		if (!ctx->player->sprites->down)
			destroy(ctx, "down.xpm not found!", 1);
		if (!ctx->player->sprites->idle)
			destroy(ctx, "idle.xpm not found!", 1);
		if (!ctx->player->sprites->left_alt)
			destroy(ctx, "left_alt.xpm not found!", 1);
		if (!ctx->player->sprites->left)
			destroy(ctx, "left.xpm not found!", 1);
		if (!ctx->player->sprites->right_alt)
			destroy(ctx, "right_alt.xpm not found!", 1);
		if (!ctx->player->sprites->right)
			destroy(ctx, "right.xpm not found!", 1);
		if (!ctx->player->sprites->up_alt)
			destroy(ctx, "up_alt.xpm not found!", 1);
		if (!ctx->player->sprites->up)
			destroy(ctx, "up.xpm not found!", 1);
	}
}

void	check_sprites_extra(t_ctx *ctx)
{
	if (ctx && ctx->player && ctx->player->sprites)
	{
		if (!ctx->player->sprites->down_left_alt)
			destroy(ctx, "down_left_alt.xpm not found!", 1);
		if (!ctx->player->sprites->down_left)
			destroy(ctx, "down_left.xpm not found!", 1);
		if (!ctx->player->sprites->down_right_alt)
			destroy(ctx, "down_right_alt.xpm not found!", 1);
		if (!ctx->player->sprites->down_right)
			destroy(ctx, "down_right.xpm not found!", 1);
		if (!ctx->player->sprites->up_left_alt)
			destroy(ctx, "up_left_alt.xpm not found!", 1);
		if (!ctx->player->sprites->up_left)
			destroy(ctx, "up_left.xpm not found!", 1);
		if (!ctx->player->sprites->up_right_alt)
			destroy(ctx, "up_right_alt.xpm not found!", 1);
		if (!ctx->player->sprites->up_right)
			destroy(ctx, "yp_right.xpm not found!", 1);
	}
}

void	check_sprites_extra_extra(t_ctx *ctx)
{
	if (ctx && ctx->player && ctx->player->sprites)
	{
		if (!ctx->player->sprites->bottom_alt)
			destroy(ctx, "bottom_alt.xpm not found!", 1);
		if (!ctx->player->sprites->bottom)
			destroy(ctx, "bottom.xpm not found!", 1);
		if (!ctx->player->sprites->top_alt)
			destroy(ctx, "top_alt.xpm not found!", 1);
		if (!ctx->player->sprites->top)
			destroy(ctx, "top.xpm not found!", 1);
		if (!ctx->player->sprites->side_l_alt)
			destroy(ctx, "side_l_alt.xpm not found!", 1);
		if (!ctx->player->sprites->side_l)
			destroy(ctx, "side_l.xpm not found!", 1);
		if (!ctx->player->sprites->side_r_alt)
			destroy(ctx, "side_r_alt.xpm not found!", 1);
		if (!ctx->player->sprites->side_r)
			destroy(ctx, "side_r.xpm not found!", 1);
	}
}

void	check_world_sprites(t_ctx *ctx)
{
	if (ctx && ctx->world && ctx->world->sprites)
		if (!ctx->world->sprites->wall)
			destroy(ctx, "wall.xpm not found!", 1);
}