/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 18:53:09 by otodd            ###   ########.fr       */
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
	t_vector2			*tl;

	p = c->player;
	s = p->sprites;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y][tl->x - 1].type != WALL)
		p->current_tile = &c->world->tiles[tl->y][tl->x - 1];
	p->pos->x = p->current_tile->pos->x;
	if (!check_border(c))
	{
		if (p->frame)
			c->put_i(c->mlx_ctx, c->root, s->left_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->left, xp(c), yp(c));
	}
}

void	right(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;
	t_vector2			*tl;

	p = c->player;
	s = p->sprites;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y][tl->x + 1].type != WALL)
		p->current_tile = &c->world->tiles[tl->y][tl->x + 1];
	p->pos->x = p->current_tile->pos->x;
	if (!check_border(c))
	{
		if (p->frame)
			c->put_i(c->mlx_ctx, c->root, s->right_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->right, xp(c), yp(c));
	}
}

void	up(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;
	t_vector2			*tl;

	p = c->player;
	s = p->sprites;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y - 1][tl->x].type != WALL)
		p->current_tile = &c->world->tiles[tl->y - 1][tl->x];
	p->pos->y = p->current_tile->pos->y;
	if (!check_border(c))
	{
		if (p->frame)
			c->put_i(c->mlx_ctx, c->root, s->up_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->up, xp(c), yp(c));
	}
}

void	down(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;
	t_vector2			*tl;

	p = c->player;
	s = p->sprites;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y + 1][tl->x].type != WALL)
		p->current_tile = &c->world->tiles[tl->y + 1][tl->x];
	p->pos->y = p->current_tile->pos->y;
	if (!check_border(c))
	{
		if (p->frame)
			c->put_i(c->mlx_ctx, c->root, s->down_alt, xp(c), yp(c));
		else
			c->put_i(c->mlx_ctx, c->root, s->down, xp(c), yp(c));
	}
}
