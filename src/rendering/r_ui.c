/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ui.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:50:03 by otodd             #+#    #+#             */
/*   Updated: 2024/02/27 12:12:35 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	moves_text(t_ctx *c)
{
	char	*a;
	char	*b;

	a = ft_itoa(c->player->moves);
	b = ft_strjoin("Moves: ", a);
	free(a);
	mlx_put_image_to_window(c->mlx_ctx,
		c->root,
		c->player->sprites->idle,
		(c->width / 2) - (SIZE + 40),
		(c->height + (SIZE / 2) - 10)
		);
	mlx_string_put(
		c->mlx_ctx,
		c->root,
		(c->width / 2) - SIZE,
		(c->height + SIZE / 2) + 10,
		0xFFFFFF,
		b
		);
	free(b);
}

void	enemys_text(t_ctx *c)
{
	char	*a;
	char	*b;

	a = ft_itoa(c->map->enemy_count);
	b = ft_strjoin("Enemys: ", a);
	free(a);
	mlx_put_image_to_window(c->mlx_ctx,
		c->root,
		c->world->sprites->enemy,
		(c->width / 2) - (SIZE - 60),
		(c->height + (SIZE / 2) - 10)
		);
	mlx_string_put(
		c->mlx_ctx,
		c->root,
		(c->width / 2) - (SIZE - 100),
		(c->height + SIZE / 2) + 10,
		0xFFFFFF,
		b
		);
	free(b);
}

void	coins_text(t_ctx *c)
{
	char	*a;
	char	*b;

	a = ft_itoa(c->player->coins_collected);
	b = ft_strjoin("Coins: ", a);
	free(a);
	mlx_put_image_to_window(c->mlx_ctx,
		c->root,
		c->world->sprites->coin,
		(c->width / 2) - (SIZE + 140),
		(c->height + (SIZE / 2) - 10)
		);
	mlx_string_put(
		c->mlx_ctx,
		c->root,
		(c->width / 2) - (SIZE + 100),
		(c->height + SIZE / 2) + 10,
		0xFFFFFF,
		b
		);
	free(b);
}
