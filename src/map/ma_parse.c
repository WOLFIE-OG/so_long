/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:45 by otodd             #+#    #+#             */
/*   Updated: 2024/02/26 16:43:31 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	position(t_ctx *c, int i, int j)
{
	c->world->tiles[i][j].pos = init_vector2();
	if (!c->world->tiles[i][j].pos)
		destroy(c, "Failed to alloc pos!", 1);
	c->world->tiles[i][j].local_pos = init_vector2();
	if (!c->world->tiles[i][j].local_pos)
		destroy(c, "Failed to alloc local_pos!", 1);
	c->world->tiles[i][j].pos->x = c->world->init_x;
	c->world->tiles[i][j].pos->y = c->world->init_y;
	c->world->tiles[i][j].local_pos->x = j;
	c->world->tiles[i][j].local_pos->y = i;
}

static void	types(t_ctx *c, int i, int j)
{
	if (c->world->tiles[i][j].type == EMPTY)
		c->world->tiles[i][j].hidden = 1;
	else if (c->world->tiles[i][j].type == COLLECT)
	{
		c->world->tiles[i][j].sprite = c->world->sprites->coin;
		c->world->tiles[i][j].sprite_alt = c->world->sprites->coin_alt;
	}
	else if (c->world->tiles[i][j].type == ENEMY)
	{
		c->world->tiles[i][j].sprite = c->world->sprites->enemy;
		c->world->tiles[i][j].sprite_alt = c->world->sprites->enemy_alt;
	}
	else if (c->world->tiles[i][j].type == EXIT)
		c->world->tiles[i][j].sprite = c->world->sprites->exit;
	else if (c->world->tiles[i][j].type == FAKE)
		c->world->tiles[i][j].sprite = c->world->sprites->wall;
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

static void	space(t_ctx *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->map->rows)
	{
		c->world->tiles[i] = malloc(c->map->columns * sizeof(t_tile));
		if (!c->world->tiles[i])
			destroy(c, "Failed to tile!", 1);
		j = 0;
		while (j < c->map->columns)
		{
			c->world->tiles[i][j].sprite = NULL;
			c->world->tiles[i][j].sprite_alt = NULL;
			c->world->tiles[i][j].type = EMPTY;
			c->world->tiles[i][j].pos = NULL;
			c->world->tiles[i][j].local_pos = NULL;
			c->world->tiles[i][j].hidden = 0;
			j++;
		}
		i++;
	}
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
			c->world->tiles[i][j].type = c->map->data[i][j];
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
	space(c);
	populate(c);
}
