/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:45 by otodd             #+#    #+#             */
/*   Updated: 2024/02/23 14:27:51 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	position(t_ctx *c, int i, int j)
{
	c->world->tiles[i][j].pos->x = c->world->init_x;
	c->world->tiles[i][j].pos->y = c->world->init_y;
	c->world->tiles[i][j].local_pos->x = j;
	c->world->tiles[i][j].local_pos->y = i;
}

static void	types(t_ctx *c, int i, int j)
{
	c->world->tiles[i][j].type = c->map->data[i][j];
	c->world->tiles[i][j].hidden = 0;
	if (c->world->tiles[i][j].type == EMPTY)
		c->world->tiles[i][j].hidden = 1;
	else if (c->world->tiles[i][j].type == COLLECT)
		c->world->tiles[i][j].sprite = c->world->sprites->coin;
	else if (c->world->tiles[i][j].type == EXIT)
		c->world->tiles[i][j].sprite = c->world->sprites->exit;
	else if (c->world->tiles[i][j].type == SPAWN)
	{
		c->player->pos->x = c->world->init_x;
		c->player->pos->y = c->world->init_y;
		c->player->current_tile = &c->world->tiles[i][j];
		c->world->tiles[i][j].sprite = c->world->sprites->spawn;
	}
	else
		c->world->tiles[i][j].sprite = c->world->sprites->wall;
}

static void	populate(t_ctx *c)
{
	int	i;
	int	j;

	i = 0;
	c->world->init_y = 0;
	while (i < c->map->rows)
	{
		j = 0;
		c->world->init_x = 0;
		while (j < c->map->columns)
		{
			position(c, i, j);
			types(c, i, j);
			c->world->init_x += SIZE;
			++j;
		}
		c->world->init_y += SIZE;
		++i;
	}
}

void	parse_map(t_ctx *c)
{
	c->world->tiles = malloc(sizeof(t_tile *) * c->map->rows);
	if (!c->world->tiles)
		destroy(c, "Failed to tiles!", 1);
	init_array(c);
	populate(c);
}
