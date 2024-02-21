/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_check_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:59:21 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 19:01:59 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	top(t_ctx *c)
{
	t_player			*p;
	t_vector2			*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y - 1][tl->x].type == WALL)
		return (1);
	return (0);
}

static int	side_l(t_ctx *c)
{
	t_player			*p;
	t_vector2			*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y][tl->x - 1].type == WALL)
		return (1);
	return (0);
}

static int	bottom(t_ctx *c)
{
	t_player			*p;
	t_vector2			*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y + 1][tl->x].type == WALL)
		return (1);
	return (0);
}

static int	side_r(t_ctx *c)
{
	t_player			*p;
	t_vector2			*tl;

	p = c->player;
	tl = p->current_tile->local_pos;
	if (c->world->tiles[tl->y][tl->x + 1].type == WALL)
		return (1);
	return (0);
}

int	check_border(t_ctx *ctx)
{
	int	i;

	i = top(ctx);
	i += side_l(ctx);
	i += bottom(ctx);
	i += side_r(ctx);
	ft_printf("%d | %c\n", i, ctx->player->direction);
	return (0);
}
