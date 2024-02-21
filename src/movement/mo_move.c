/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 22:13:32 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	idle(t_ctx *c)
{
	render_idle(c);
}

void	left(t_ctx *c)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y][tl->x - 1].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y][tl->x - 1];
		c->player->moves++;
	}
	p->pos->x = p->current_tile->pos->x;
	render_left(c);
}

void	right(t_ctx *c)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y][tl->x + 1].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y][tl->x + 1];
		c->player->moves++;
	}
	p->pos->x = p->current_tile->pos->x;
	render_right(c);
}

void	up(t_ctx *c)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y - 1][tl->x].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y - 1][tl->x];
		c->player->moves++;
	}
	p->pos->y = p->current_tile->pos->y;
	render_up(c);
}

void	down(t_ctx *c)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y + 1][tl->x].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y + 1][tl->x];
		c->player->moves++;
	}
	p->pos->y = p->current_tile->pos->y;
	render_down(c);
}
