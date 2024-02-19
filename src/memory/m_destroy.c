/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_destroy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:14:32 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 21:44:28 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	destroy(t_ctx *ctx, char *message, int type)
{
	free_player(ctx);
	free_world(ctx);
	if (ctx)
	{
		if (ctx->mlx_ctx && ctx->root)
		{
			mlx_clear_window(ctx->mlx_ctx, ctx->root);
			mlx_destroy_window(ctx->mlx_ctx, ctx->root);
		}
		if (ctx->map)
		{
			ft_free_array(ctx->map, ft_strarraylen(ctx->map));
			free(ctx->map);
		}
		mlx_destroy_display(ctx->mlx_ctx);
		free(ctx->mlx_ctx);
		free(ctx);
	}
	if (type)
		ft_printf("["BRED"ERROR"RESET"]	%s\n", message);
	else
		ft_printf("["BGRN"INFO"RESET"]	%s\n", message);
	exit(EXIT_FAILURE);
}
