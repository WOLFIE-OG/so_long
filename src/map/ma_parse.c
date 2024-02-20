/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:45 by otodd             #+#    #+#             */
/*   Updated: 2024/02/20 17:43:59 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	init_array(t_ctx *c)
{
	int	i;

	i = 0;
	c->world->tiles = malloc(sizeof(t_tile *) * c->map->rows);
	while (i < c->map->rows)
	{
		c->world->tiles[i] = malloc(c->map->columns * sizeof(t_tile));
		++i;
	}
}

static void	position(t_ctx *c, int i, int j)
{
	c->world->tiles[i][j].pos = malloc(sizeof(t_vector2));
	if (!c->world->tiles[i][j].pos)
		destroy(c, "Failed to alloc pos!", 1);
	c->world->tiles[i][j].pos->x = c->world->init_k;
	c->world->tiles[i][j].pos->y = c->world->init_l;
}

static void	populate(t_ctx *c)
{
	int	i;
	int	j;

	i = 0;
	c->world->init_l = 0;
	while (i < c->map->rows)
	{
		j = 0;
		c->world->init_k = 0;
		while (j < c->map->columns)
		{
			c->world->tiles[i][j].sprite = c->world->sprites->wall;
			c->world->tiles[i][j].type = c->map->data[i][j];
			position(c, i, j);
			if (c->world->tiles[i][j].type == '0')
				c->world->tiles[i][j].hidden = true;
			else if (c->world->tiles[i][j].type == 'P')
			{
				c->start_pos->x = c->world->init_k;
				c->start_pos->y = c->world->init_l;
			}
			else
				c->world->tiles[i][j].hidden = false;
			c->world->init_k += 32;
			++j;
		}
		c->world->init_l += 32;
		++i;
	}
}

void	parse_map(t_ctx *ctx)
{
	init_array(ctx);
	populate(ctx);
}
