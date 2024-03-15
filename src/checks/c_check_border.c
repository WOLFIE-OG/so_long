/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:59:21 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 12:49:55 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	top(t_ctx *c)
{
	if (c->world->tiles[c->player->current_tile->map_pos->y - 1]
		[c->player->current_tile->map_pos->x].type == T_WALL)
		return (1);
	return (0);
}

static int	side_l(t_ctx *c)
{
	if (c->world->tiles[c->player->current_tile->map_pos->y]
		[c->player->current_tile->map_pos->x - 1].type == T_WALL)
		return (1);
	return (0);
}

static int	bottom(t_ctx *c)
{
	if (c->world->tiles[c->player->current_tile->map_pos->y + 1]
		[c->player->current_tile->map_pos->x].type == T_WALL)
		return (1);
	return (0);
}

static int	side_r(t_ctx *c)
{
	if (c->world->tiles[c->player->current_tile->map_pos->y]
		[c->player->current_tile->map_pos->x + 1].type == T_WALL)
		return (1);
	return (0);
}

int	check_border(t_ctx *c)
{
	int		i;

	i = (top(c) && c->player->direction == M_UP);
	i += (side_l(c) && c->player->direction == M_LEFT);
	i += (bottom(c) && c->player->direction == M_DOWN);
	i += (side_r(c) && c->player->direction == M_RIGHT);
	if (i > 0)
	{
		if (c->player->direction == M_UP)
			render_border_top(c);
		else if (c->player->direction == M_DOWN)
			render_border_bottom(c);
		else if (c->player->direction == M_LEFT)
			render_border_side_l(c);
		else if (c->player->direction == M_RIGHT)
			render_border_side_r(c);
		return (1);
	}
	return (0);
}
