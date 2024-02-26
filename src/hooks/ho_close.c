/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:37 by otodd             #+#    #+#             */
/*   Updated: 2024/02/26 14:50:01 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	close_program(t_ctx *c)
{
	mlx_clear_window(c->mlx_ctx, c->root);
	c->game_running = 0;
	mlx_loop_end(c->mlx_ctx);
	return (0);
}
