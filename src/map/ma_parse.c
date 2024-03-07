/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:45 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:20:32 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	position(t_ctx *c, int i, int j)
{
	c->world->tiles[i][j].win_pos = vector2();
	if (!c->world->tiles[i][j].win_pos)
		destroy(c, "Failed to alloc pos!", true);
	c->world->tiles[i][j].map_pos = vector2();
	if (!c->world->tiles[i][j].map_pos)
		destroy(c, "Failed to alloc map_pos!", true);
	c->world->tiles[i][j].win_pos->x = c->world->init_x;
	c->world->tiles[i][j].win_pos->y = c->world->init_y;
	c->world->tiles[i][j].map_pos->x = j;
	c->world->tiles[i][j].map_pos->y = i;
}

static void	types(t_ctx *c, int i, int j)
{
	if (c->world->tiles[i][j].type == T_EMPTY)
		c->world->tiles[i][j].hidden = true;
	else if (c->world->tiles[i][j].type == T_COLLECT)
	{
		c->world->tiles[i][j].sprite = c->sprites[COIN];
		c->world->tiles[i][j].sprite_alt = c->sprites[COIN_ALT];
	}
	else if (c->world->tiles[i][j].type == T_ENEMY)
	{
		c->world->tiles[i][j].sprite = c->sprites[ENEMY];
		c->world->tiles[i][j].sprite_alt = c->sprites[ENEMY_ALT];
	}
	else if (c->world->tiles[i][j].type == T_EXIT)
		c->world->tiles[i][j].sprite = c->sprites[EXIT];
	else if (c->world->tiles[i][j].type == T_FAKE)
		c->world->tiles[i][j].sprite = c->sprites[WALL];
	else if (c->world->tiles[i][j].type == T_SPAWN)
	{
		c->player->win_pos->x = c->world->init_x;
		c->player->win_pos->y = c->world->init_y;
		c->player->current_tile = &c->world->tiles[i][j];
		c->world->tiles[i][j].sprite = c->sprites[SPAWN];
	}
	else
		c->world->tiles[i][j].sprite = c->sprites[WALL];
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
			destroy(c, "Failed to tile!", true);
		j = 0;
		while (j < c->map->columns)
		{
			c->world->tiles[i][j].sprite = NULL;
			c->world->tiles[i][j].sprite_alt = NULL;
			c->world->tiles[i][j].type = T_EMPTY;
			c->world->tiles[i][j].win_pos = NULL;
			c->world->tiles[i][j].map_pos = NULL;
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
		destroy(c, "Failed to tiles!", true);
	space(c);
	populate(c);
}
