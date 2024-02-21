/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:29:22 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 15:31:14 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map(t_ctx *ctx)
{
	if (ctx->map)
	{
		if (ctx->map->data)
		{
			ft_free_array(ctx->map->data, ft_strarraylen(ctx->map->data));
			free(ctx->map->data);
		}
		free(ctx->map);
	}
}
