/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:35 by otodd             #+#    #+#             */
/*   Updated: 2024/02/26 14:39:24 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ui_text(t_ctx *c)
{
	char	*a;
	char	*b;

	a = ft_itoa(c->player->moves);
	b = ft_strjoin("Moves: ", a);
	free(a);
	mlx_string_put(
		c->mlx_ctx,
		c->root,
		(c->width / 2) - SIZE,
		(c->height + SIZE / 2) - 5,
		0xFFFFFF,
		b
		);
	free(b);
}

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
	tile_detect(c);
	idle_check(c);
	ui_text(c);
	mlx_put_image_to_window(c->mlx_ctx, c->root, c->buffer, 0, 0);
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
