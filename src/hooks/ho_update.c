/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:35 by otodd             #+#    #+#             */
/*   Updated: 2024/02/20 17:39:44 by otodd            ###   ########.fr       */
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

static void	alt_shift(t_ctx *c)
{
	if (c->player->is_alt)
		c->player->is_alt = 0;
	else
		c->player->is_alt = 1;
}

static void	extended(t_ctx *c)
{
	alt_shift(c);
	debug_text(c);
}

static void	draw_world(t_ctx *c)
{
	int	i;
	int j;

	i = 0;
	while (i < c->map->rows)
	{
		j = 0;
		while (j < c->map->columns)
		{
			if (!c->world->tiles[i][j].hidden)
				c->put_i(
					c->mlx_ctx,
					c->root,
					c->world->tiles[i][j].sprite,
					c->world->tiles[i][j].pos->x,
					c->world->tiles[i][j].pos->y
				);
			j++;
		}
		i++;
	}
}


int	update(t_ctx *ctx)
{
	if (!ctx->game_running)
		return (0);
	ft_printf("%d x %d\n", ctx->player->pos->x, ctx->player->pos->y);
	mlx_clear_window(ctx->mlx_ctx, ctx->root);
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
	draw_world(ctx);
	extended(ctx);
	usleep(166667);
	return (0);
}
