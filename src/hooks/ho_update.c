/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:35 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 18:53:55 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	debug_text(t_ctx *c)
{
	char	*a;
	char	*b;
	char	*d;
	char	*i;
	char	*j;

	i = ft_itoa(c->player->pos->x);
	j = ft_itoa(c->player->pos->y);
	a = ft_strjoin("X: ", i);
	b = ft_strjoin(" Y: ", j);
	d = ft_strjoin(a, b);
	free(a);
	free(b);
	free(i);
	free(j);
	mlx_string_put(
		c->mlx_ctx,
		c->root,
		(c->width / 2) - SIZE,
		c->height + SIZE / 2,
		0xFFFFFF,
		d
		);
	free(d);
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
	debug_text(c);
}

int	update(t_ctx *c)
{
	if (!c->game_running)
		return (0);
	mlx_clear_window(c->mlx_ctx, c->root);
	draw_world(c);
	if (c->player->direction == 'W')
		up(c);
	else if (c->player->direction == 'S')
		down(c);
	else if (c->player->direction == 'A')
		left(c);
	else if (c->player->direction == 'D')
		right(c);
	else if (c->player->direction == '1')
		up_left(c);
	else if (c->player->direction == '2')
		up_right(c);
	else if (c->player->direction == '3')
		down_left(c);
	else if (c->player->direction == '4')
		down_right(c);
	else
		idle(c);
	// ft_printf("Current Tile: X: %d | Y: %d | Type: %c\n", c->player->current_tile->pos->x, c->player->current_tile->pos->y, c->player->current_tile->type);
	extended(c);
	usleep(166667);
	return (0);
}
