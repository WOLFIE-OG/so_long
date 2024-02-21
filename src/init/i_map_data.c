/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_map_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:24:37 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 22:26:56 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_array(t_ctx *c)
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
			c->world->tiles[i][j].type = EMPTY;
			c->world->tiles[i][j].pos = init_vector2();
			if (!c->world->tiles[i][j].pos)
				destroy(c, "Failed to alloc pos!", 1);
			c->world->tiles[i][j].local_pos = init_vector2();
			if (!c->world->tiles[i][j].local_pos)
				destroy(c, "Failed to alloc local_pos!", 1);
			j++;
		}
		i++;
	}
}
