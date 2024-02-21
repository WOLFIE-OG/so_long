/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 15:37:53 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	up_left(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->pos->x > SIZE)
		p->pos->x -= SIZE;
	if (p->pos->y > SIZE / 2)
		p->pos->y -= SIZE;
	if (p->frame)
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
	if (p->pos->x < c->width - SIZE)
		p->pos->x += SIZE;
	if (p->pos->y > SIZE / 2)
		p->pos->y -= SIZE;
	if (p->frame)
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
	if (p->pos->x > SIZE)
		p->pos->x -= SIZE;
	if (p->pos->y < c->height - SIZE)
		p->pos->y += SIZE;
	if (p->frame)
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
	if (p->pos->x < c->width - SIZE)
		p->pos->x += SIZE;
	if (p->pos->y < c->height - SIZE)
		p->pos->y += SIZE;
	if (p->frame)
		c->put_i(c->mlx_ctx, c->root, s->down_right_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->down_right, xp(c), yp(c));
}
