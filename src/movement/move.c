/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 14:54:41 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	idle(t_ctx *ctx)
{
	t_player			*p;
	t_player_sprites	*s;

	p = ctx->player;
	s = p->sprites;
	ctx->put_i(ctx->mlx_ctx, ctx->root, s->idle, p->x, p->y);
}

void	left(t_ctx *ctx)
{
	t_player			*p;
	t_player_sprites	*s;

	p = ctx->player;
	s = p->sprites;
	if (p->x != 0)
		p->x -= SPEED;
	if (p->is_alt)
		ctx->put_i(ctx->mlx_ctx, ctx->root, s->left_alt, p->x, p->y);
	else
		ctx->put_i(ctx->mlx_ctx, ctx->root, s->left, p->x, p->y);
}

void	right(t_ctx *ctx)
{
	t_player			*p;
	t_player_sprites	*s;

	p = ctx->player;
	s = p->sprites;
	if (p->x != ctx->width - 30)
		p->x += SPEED;
	if (p->is_alt)
		ctx->put_i(ctx->mlx_ctx, ctx->root, s->right_alt, p->x, p->y);
	else
		ctx->put_i(ctx->mlx_ctx, ctx->root, s->right, p->x, p->y);
}

void	up(t_ctx *ctx)
{
	t_player			*p;
	t_player_sprites	*s;

	p = ctx->player;
	s = p->sprites;
	if (p->y != 0)
		p->y -= SPEED;
	if (p->is_alt)
		ctx->put_i(ctx->mlx_ctx, ctx->root, s->up_alt, p->x, p->y);
	else
		ctx->put_i(ctx->mlx_ctx, ctx->root, s->up, p->x, p->y);
}

void	down(t_ctx *ctx)
{
	t_player			*p;
	t_player_sprites	*s;

	p = ctx->player;
	s = p->sprites;
	if (p->y != ctx->height - 30)
		p->y += SPEED;
	if (p->is_alt)
		ctx->put_i(ctx->mlx_ctx, ctx->root, s->down_alt, p->x, p->y);
	else
		ctx->put_i(ctx->mlx_ctx, ctx->root, s->down, p->x, p->y);
}
