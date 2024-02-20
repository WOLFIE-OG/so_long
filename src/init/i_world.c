/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/02/20 17:37:30 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	tile(t_ctx *c)
{
	int				w;
	int				h;

	c->world->sprites = malloc(sizeof(t_world_sprites));
	if (!c->world->sprites)
		destroy(c, "Failed to alloc tile!", 1);
	w = 32;
	h = 32;
	c->world->sprites->wall = les(c, "wall.xpm", w, h);
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
	parse_map(ctx);
}
