/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 22:31:00 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	up_left(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->x > lround(0.02f * c->width))
		p->x -= SPEED;
	if (p->y > lround(0.04f * c->height))
		p->y -= SPEED;
	if (p->is_alt)
		c->put_i(c->mlx_ctx, c->root, s->up_left_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->up_left, xp(c), yp(c));
}

void	up_right(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->x < c->width - lround(0.02f * c->width))
		p->x += SPEED;
	if (p->y > lround(0.04f * c->height))
		p->y -= SPEED;
	if (p->is_alt)
		c->put_i(c->mlx_ctx, c->root, s->up_right_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->up_right, xp(c), yp(c));
}

void	down_left(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->x > lround(0.02f * c->width))
		p->x -= SPEED;
	if (p->y < c->height - lround(0.02f * c->height))
		p->y += SPEED;
	if (p->is_alt)
		c->put_i(c->mlx_ctx, c->root, s->down_left_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->down_left, xp(c), yp(c));
}

void	down_right(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->x < c->width - lround(0.02f * c->width))
		p->x += SPEED;
	if (p->y < c->height - lround(0.02f * c->height))
		p->y += SPEED;
	if (p->is_alt)
		c->put_i(c->mlx_ctx, c->root, s->down_right_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->down_right, xp(c), yp(c));
}