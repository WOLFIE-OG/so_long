/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_check_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:59:21 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 22:37:10 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	top(t_ctx *c)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y - 1][tl->x].type == WALL)
		return (1);
	return (0);
}

static int	side_l(t_ctx *c)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y][tl->x - 1].type == WALL)
		return (1);
	return (0);
}

static int	bottom(t_ctx *c)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y + 1][tl->x].type == WALL)
		return (1);
	return (0);
}

static int	side_r(t_ctx *c)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y][tl->x + 1].type == WALL)
		return (1);
	return (0);
}

int	check_border(t_ctx *c)
{
	int		i;
	char	d;

	d = c->player->direction;
	i = (top(c) && d == UP);
	i += (side_l(c) && d == LEFT);
	i += (bottom(c) && d == DOWN);
	i += (side_r(c) && d == RIGHT);
	if (i > 0)
	{
		if (d == UP)
			render_border_top(c);
		else if (d == DOWN)
			render_border_bottom(c);
		else if (d == LEFT)
			render_border_side_l(c);
		else if (d == RIGHT)
			render_border_side_r(c);
		return (1);
	}
	return (0);
}
