/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tiles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:33:52 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:09:33 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_tiles(t_ctx *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->map->rows)
	{
		j = 0;
		while (j < c->map->columns)
		{
			free(c->world->tiles[i][j].win_pos);
			free(c->world->tiles[i][j].map_pos);
			j++;
		}
		free(c->world->tiles[i]);
		i++;
	}
	free(c->world->tiles);
}
