/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/03/05 18:46:37 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sprites(t_ctx *c)
{
	int				w;
	int				h;

	c->world->sprites = malloc(sizeof(t_world_sprites));
	if (!c->world->sprites)
		destroy(c, "Failed to alloc sprites!", true);
	w = SIZE;
	h = SIZE;
	c->world->sprites->wall = les(c, "wall.xpm", w, h);
	c->world->sprites->coin = les(c, "coin.xpm", w, h);
	c->world->sprites->coin_alt = les(c, "coin_alt.xpm", w, h);
	c->world->sprites->exit = les(c, "exit.xpm", w, h);
	c->world->sprites->spawn = les(c, "spawn.xpm", w, h);
	c->world->sprites->enemy = les(c, "enemy.xpm", w, h);
	c->world->sprites->enemy_alt = les(c, "enemy_alt.xpm", w, h);
}

static void	world(t_ctx *c)
{
	c->world = malloc(sizeof(t_world));
	if (!c->world)
		destroy(c, "Failed to alloc world!", true);
	c->world->easter_egg = false;
	c->world->exit_msg = false;
	ft_printf("["BBLU"WORLD"RESET"]		Created world\n");
}

void	init_world(t_ctx *c)
{
	world(c);
	sprites(c);
	check_world_sprites(c);
	parse_map(c);
}
