/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:04:50 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:14:55 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	put(t_ctx *c, int i, int j)
{
	if (!c->player->frame)
	{
		if (c->world->tiles[i][j].sprite_alt)
			c->world->tiles[i][j].sprite = c->world->tiles[i][j].sprite_alt;
	}
	put_buf(
		c,
		c->world->tiles[i][j].sprite,
		c->world->tiles[i][j].win_pos->x,
		c->world->tiles[i][j].win_pos->y
		);
}

void	draw_world(t_ctx *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->map->rows)
	{
		j = 0;
		while (j < c->map->columns)
		{
			if (!c->world->tiles[i][j].hidden)
				put(c, i, j);
			j++;
		}
		i++;
	}
}
