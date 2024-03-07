/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 18:24:45 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sprites(t_ctx *c)
{
	const int	w = SIZE;
	const int	h = SIZE;
	int			i;

	i = NUM_SPRITES - 7;
	while (i < NUM_SPRITES)
	{
		c->sprites[c->sprite_table[i].sprite]
			= lws(c, c->sprite_table[i].file_name, w, h);
		i++;
	}
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
	parse_map(c);
}
