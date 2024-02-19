/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_check_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:59:21 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 16:58:49 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	top(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->pos->y < SPEED)
	{
		if (p->is_alt)
			c->put_i(c->mlx_ctx, c->root, s->top_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->top, xp(c), yp(c));
		return (1);
	}
	return (0);
}

static int	side_l(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->pos->x < SPEED)
	{
		if (p->is_alt)
			c->put_i(c->mlx_ctx, c->root, s->side_l_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->side_l, xp(c), yp(c));
		return (1);
	}
	return (0);
}

static int	bottom(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->pos->y == c->height - SPEED)
	{
		if (p->is_alt)
			c->put_i(c->mlx_ctx, c->root, s->bottom_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->bottom, xp(c), yp(c));
		return (1);
	}
	return (0);
}

static int	side_r(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->pos->x == c->width - SPEED)
	{
		if (p->is_alt)
			c->put_i(c->mlx_ctx, c->root, s->side_r_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->side_r, xp(c), yp(c));
		return (1);
	}
	return (0);
}

int	check_border(t_ctx *ctx)
{
	if (top(ctx))
		return (1);
	else if (side_l(ctx))
		return (2);
	else if (bottom(ctx))
		return (3);
	else if (side_r(ctx))
		return (4);
	return (0);
}
