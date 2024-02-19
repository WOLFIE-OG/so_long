/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:35 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 21:54:49 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	debug_text(t_ctx *ctx)
{
	char	*a;
	char	*b;
	char	*c;
	char	*i;
	char	*j;

	i = ft_itoa(ctx->player->pos->x);
	j = ft_itoa(ctx->player->pos->y);
	a = ft_strjoin("X: ", i);
	b = ft_strjoin(" Y: ", j);
	c = ft_strjoin(a, b);
	free(a);
	free(b);
	free(i);
	free(j);
	mlx_string_put(
		ctx->mlx_ctx,
		ctx->root,
		ctx->player->pos->x - 64,
		ctx->player->pos->y - 64,
		0x00bfff,
		c
		);
	free(c);
}

static void	alt_shift(t_ctx *ctx)
{
	if (ctx->player->is_alt)
		ctx->player->is_alt = 0;
	else
		ctx->player->is_alt = 1;
}

static void	extended(t_ctx *ctx)
{
	alt_shift(ctx);
	debug_text(ctx);
}

static void	draw_world(t_ctx *ctx)
{
	int	w;
	int	h;

	w = ctx->width;
	h = ctx->height;
	while (w)
	{
		ctx->put_i(ctx->mlx_ctx, ctx->root, ctx->world->sprites->wall, w - SPEED, 0);
		w -= SPEED;
	}
	while (h)
	{
		ctx->put_i(ctx->mlx_ctx, ctx->root, ctx->world->sprites->wall, 0, h - SPEED);
		h -= SPEED;
	}
}

int	update(t_ctx *ctx)
{
	if (!ctx->game_running)
		return (0);
	mlx_clear_window(ctx->mlx_ctx, ctx->root);
	draw_world(ctx);
	if (ctx->player->direction == 'W')
		up(ctx);
	else if (ctx->player->direction == 'S')
		down(ctx);
	else if (ctx->player->direction == 'A')
		left(ctx);
	else if (ctx->player->direction == 'D')
		right(ctx);
	else if (ctx->player->direction == '1')
		up_left(ctx);
	else if (ctx->player->direction == '2')
		up_right(ctx);
	else if (ctx->player->direction == '3')
		down_left(ctx);
	else if (ctx->player->direction == '4')
		down_right(ctx);
	else
		idle(ctx);
	extended(ctx);
	usleep(166667);
	return (0);
}
