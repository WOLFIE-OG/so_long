/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 16:43:44 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sprites(t_ctx *c)
{
	int				w;
	int				h;

	c->world->sprites = malloc(sizeof(t_world_sprites));
	if (!c->world->sprites)
		destroy(c, "Failed to alloc sprites!", 1);
	w = SIZE;
	h = SIZE;
	c->world->sprites->wall = les(c, "wall.xpm", w, h);
	c->world->sprites->coin = les(c, "coin.xpm", w, h);
	c->world->sprites->exit = les(c, "exit.xpm", w, h);
	c->world->sprites->spawn = les(c, "spawn.xpm", w, h);
}

static void	world(t_ctx *c)
{
	c->world = malloc(sizeof(t_world));
	if (!c->world)
		destroy(c, "Failed to alloc world!", 1);
	ft_printf("["BBLU"WORLD"RESET"]		Created world\n");
}

void	init_world(t_ctx *ctx)
{
	world(ctx);
	sprites(ctx);
	check_world_sprites(ctx);
	parse_map(ctx);
}
