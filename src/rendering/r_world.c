/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:04:50 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 17:45:11 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
				c->put_i(
					c->mlx_ctx,
					c->root,
					c->world->tiles[i][j].sprite,
					c->world->tiles[i][j].pos->x,
					c->world->tiles[i][j].pos->y
				);
			j++;
		}
		i++;
	}
}
