/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 12:47:53 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	up_left(t_ctx *c)
{
	if (c->world->tiles[c->player->current_tile->map_pos->y - 1]
		[c->player->current_tile->map_pos->x].type != T_WALL)
		up(c, false);
	if (c->world->tiles[c->player->current_tile->map_pos->y]
		[c->player->current_tile->map_pos->x - 1].type != T_WALL)
		left(c, false);
	render_up_left(c);
}

void	up_right(t_ctx *c)
{
	if (c->world->tiles[c->player->current_tile->map_pos->y - 1]
		[c->player->current_tile->map_pos->x].type != T_WALL)
		up(c, false);
	if (c->world->tiles[c->player->current_tile->map_pos->y]
		[c->player->current_tile->map_pos->x + 1].type != T_WALL)
		right(c, false);
	render_up_right(c);
}

void	down_left(t_ctx *c)
{
	if (c->world->tiles[c->player->current_tile->map_pos->y + 1]
		[c->player->current_tile->map_pos->x].type != T_WALL)
		down(c, false);
	if (c->world->tiles[c->player->current_tile->map_pos->y]
		[c->player->current_tile->map_pos->x - 1].type != T_WALL)
		left(c, false);
	render_down_left(c);
}

void	down_right(t_ctx *c)
{
	if (c->world->tiles[c->player->current_tile->map_pos->y + 1]
		[c->player->current_tile->map_pos->x].type != T_WALL)
		down(c, false);
	if (c->world->tiles[c->player->current_tile->map_pos->y]
		[c->player->current_tile->map_pos->x + 1].type != T_WALL)
		right(c, false);
	render_down_right(c);
}
