/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:18:21 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	up_left(t_ctx *c)
{
	t_vector2	*tl;

	tl = c->player->current_tile->map_pos;
	if (c->world->tiles[tl->y - 1][tl->x].type != T_WALL)
		up(c, false);
	if (c->world->tiles[tl->y][tl->x - 1].type != T_WALL)
		left(c, false);
	render_up_left(c);
}

void	up_right(t_ctx *c)
{
	t_vector2	*tl;

	tl = c->player->current_tile->map_pos;
	if (c->world->tiles[tl->y - 1][tl->x].type != T_WALL)
		up(c, false);
	if (c->world->tiles[tl->y][tl->x + 1].type != T_WALL)
		right(c, false);
	render_up_right(c);
}

void	down_left(t_ctx *c)
{
	t_vector2	*tl;

	tl = c->player->current_tile->map_pos;
	if (c->world->tiles[tl->y + 1][tl->x].type != T_WALL)
		down(c, false);
	if (c->world->tiles[tl->y][tl->x - 1].type != T_WALL)
		left(c, false);
	render_down_left(c);
}

void	down_right(t_ctx *c)
{
	t_vector2	*tl;

	tl = c->player->current_tile->map_pos;
	if (c->world->tiles[tl->y + 1][tl->x].type != T_WALL)
		down(c, false);
	if (c->world->tiles[tl->y][tl->x + 1].type != T_WALL)
		right(c, false);
	render_down_right(c);
}
