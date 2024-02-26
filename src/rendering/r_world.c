/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:04:50 by otodd             #+#    #+#             */
/*   Updated: 2024/02/26 13:33:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	put(t_ctx *c, int i, int j)
{
	t_img	*s;

	s = c->world->tiles[i][j].sprite;
	if (!c->player->frame)
	{
		if (c->world->tiles[i][j].sprite_alt)
			s = c->world->tiles[i][j].sprite_alt;
	}
	put_buf(
		c,
		s,
		c->world->tiles[i][j].pos->x,
		c->world->tiles[i][j].pos->y
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
