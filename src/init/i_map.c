/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:00:36 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 17:54:31 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	*path(t_ctx *ctx, char *name)
{
	char	*tmp;

	tmp = ft_strjoin("./res/maps/", name);
	if (!tmp)
	{
		free(tmp);
		destroy(ctx, "Failed to join str!", 1);
	}
	return (tmp);
}

void	init_map(t_ctx *ctx, char *name)
{
	char	*tmp;

	tmp = path(ctx, name);
	ctx->map = malloc(sizeof(t_map));
	if (!ctx->map)
		destroy(ctx, "Failed to alloc map!", 1);
	ctx->map->coin_count = 0;
	ctx->map->empty_count = 0;
	ctx->map->exit_count = 0;
	ctx->map->spawn_count = 0;
	ctx->map->empty_count = 0;
	ctx->map->data = load_map(tmp);
	if (!ctx->map->data)
	{
		free(tmp);
		destroy(ctx, "Failed to load map!", 1);
	}
	free(tmp);
	ctx->map->rows = get_height(ctx);
	ctx->map->columns = get_width(ctx);
	if (!check_map(ctx))
		destroy(ctx, "Map is invalid!", 1);
}
