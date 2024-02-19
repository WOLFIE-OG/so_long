/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 21:46:56 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	tile(t_ctx *c)
{
	int				w;
	int				h;
	t_world_sprites	*tile;

	tile = malloc(sizeof(t_world_sprites));
	c->world->sprites = tile;
	if (!tile)
		destroy(c, "Failed to alloc tile!", 1);
	w = 32;
	h = 32;
	tile->wall = les(c, "wall.xpm", w, h);
}

static void	world(t_ctx *c)
{
	t_world	*world;

	world = malloc(sizeof(t_world));
	c->world = world;
	if (!world)
		destroy(c, "Failed to alloc world!", 1);
	ft_printf("["BBLU"WORLD"RESET"]		Created world\n");
}

void	init_world(t_ctx *ctx)
{
	world(ctx);
	tile(ctx);
	check_world_sprites(ctx);
}
