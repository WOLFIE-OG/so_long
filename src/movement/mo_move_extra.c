/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 16:57:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	up_left(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->pos->x > SPEED)
		p->pos->x -= SPEED;
	if (p->pos->y > 16)
		p->pos->y -= SPEED;
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
	if (p->pos->x < c->width - SPEED)
		p->pos->x += SPEED;
	if (p->pos->y > 16)
		p->pos->y -= SPEED;
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
	if (p->pos->x > SPEED)
		p->pos->x -= SPEED;
	if (p->pos->y < c->height - SPEED)
		p->pos->y += SPEED;
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
	if (p->pos->x < c->width - SPEED)
		p->pos->x += SPEED;
	if (p->pos->y < c->height - SPEED)
		p->pos->y += SPEED;
	if (p->is_alt)
		c->put_i(c->mlx_ctx, c->root, s->down_right_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->down_right, xp(c), yp(c));
}
