/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:35 by otodd             #+#    #+#             */
/*   Updated: 2024/02/27 14:03:11 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	alt_shift(t_ctx *c)
{
	if (c->player->frame)
		c->player->frame = 0;
	else
		c->player->frame = 1;
}

static void	extended(t_ctx *c)
{
	alt_shift(c);
	tile_check(c);
	idle_check(c);
	mlx_put_image_to_window(c->mlx_ctx, c->root, c->buffer, 0, 0);
	moves_text(c);
	enemys_text(c);
	coins_text(c);
	usleep(166667);
}

int	update(t_ctx *c)
{
	if (!c->game_running)
		return (0);
	mlx_clear_window(c->mlx_ctx, c->root);
	ft_bzero(c->buffer->data, c->buffer->size_line * c->height);
	draw_world(c);
	if (c->player->direction == UP)
		up(c, true);
	else if (c->player->direction == LEFT)
		left(c, true);
	else if (c->player->direction == DOWN)
		down(c, true);
	else if (c->player->direction == RIGHT)
		right(c, true);
	else if (c->player->direction == UP_LEFT)
		up_left(c);
	else if (c->player->direction == UP_RIGHT)
		up_right(c);
	else if (c->player->direction == DOWN_LEFT)
		down_left(c);
	else if (c->player->direction == DOWN_RIGHT)
		down_right(c);
	else
		idle(c);
	extended(c);
	return (0);
}
