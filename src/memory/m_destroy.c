/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_destroy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:14:32 by otodd             #+#    #+#             */
/*   Updated: 2024/03/04 17:08:00 by otodd            ###   ########.fr       */
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

void	destroy(t_ctx *c, char *message, bool is_error)
{
	if (c)
	{
		free_player(c);
		free_world(c);
		if (c->buffer)
			c->des_i(c->mlx_ctx, c->buffer);
		if (c->mlx_ctx)
		{
			if (c->root)
			{
				free(c->win_title);
				mlx_clear_window(c->mlx_ctx, c->root);
				mlx_destroy_window(c->mlx_ctx, c->root);
			}
			free(c->mlx_ctx);
		}
		free_map(c);
		free(c);
	}
	put_msg(is_error, message);
	if (is_error)
		exit(EXIT_FAILURE);
}
