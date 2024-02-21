/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tiles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:33:52 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 16:43:39 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_tiles(t_ctx *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->map->rows)
	{
		j = 0;
		while (j < ctx->map->columns)
		{
			free(ctx->world->tiles[i][j].pos);
			free(ctx->world->tiles[i][j].local_pos);
			j++;
		}
		free(ctx->world->tiles[i]);
		i++;
	}
	free(ctx->world->tiles);
}
