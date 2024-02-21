/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_destroy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:14:32 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 15:31:09 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	put_msg(bool is_error, char *message)
{
	if (is_error)
		ft_printf("["BRED"ERROR"RESET"]		%s\n", message);
	else
		ft_printf("["BGRN"INFO"RESET"]		%s\n", message);
}

void	destroy(t_ctx *ctx, char *message, bool is_error)
{
	if (ctx)
	{
		free_player(ctx);
		free_world(ctx);
		if (ctx->mlx_ctx)
		{
			if (ctx->root)
			{
				mlx_clear_window(ctx->mlx_ctx, ctx->root);
				mlx_destroy_window(ctx->mlx_ctx, ctx->root);
			}
			mlx_destroy_display(ctx->mlx_ctx);
			free(ctx->mlx_ctx);
		}
		free_map(ctx);
		free(ctx);
	}
	put_msg(is_error, message);
	exit(EXIT_FAILURE);
}
