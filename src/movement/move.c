/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 22:14:53 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	idle(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	c->put_i(c->mlx_ctx, c->root, s->idle, xp(c), yp(c));
}

void	left(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->x > lround(0.02f * c->width))
		p->x -= SPEED;
	if (check_border(c) != 2)
	{
		if (p->is_alt)
			c->put_i(c->mlx_ctx, c->root, s->left_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->left, xp(c), yp(c));
	}
}

void	right(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->x < c->width - lround(0.02f * c->width))
		p->x += SPEED;
	if (check_border(c) != 4)
	{
		if (p->is_alt)
			c->put_i(c->mlx_ctx, c->root, s->right_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->right, xp(c), yp(c));
	}
}

void	up(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->y > lround(0.04f * c->height))
		p->y -= SPEED;
	if (check_border(c) != 1)
	{
		if (p->is_alt)
			c->put_i(c->mlx_ctx, c->root, s->up_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->up, xp(c), yp(c));
	}
}

void	down(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->y < c->height - lround(0.02f * c->height))
		p->y += SPEED;
	if (check_border(c) != 3)
	{
		if (p->is_alt)
			c->put_i(c->mlx_ctx, c->root, s->down_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->down, xp(c), yp(c));
	}
}
