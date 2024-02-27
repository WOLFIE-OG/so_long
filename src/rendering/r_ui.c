/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ui.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:50:03 by otodd             #+#    #+#             */
/*   Updated: 2024/02/27 15:13:57 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	moves_text(t_ctx *c)
{
	char	*a;
	char	*b;
	int		w;
	int		h;

	a = ft_itoa(c->player->moves);
	b = ft_strjoin("Moves: ", a);
	free(a);
	if (c->width < (SIZE * 15))
	{
		w = (c->width / 2) - (SIZE / 2);
		h = (c->height + ((SIZE / 2) * 3) + 6);
	}
	else
	{
		w = (c->width / 2);
		h = (c->height + SIZE) - 2;
	}
	mlx_string_put(c->mlx_ctx, c->root, w, h, 0xFFFFFF, b);
	free(b);
}

void	enemys_text(t_ctx *c)
{
	char	*a;
	char	*b;
	int		w;
	int		h;

	a = ft_itoa(c->map->enemy_count);
	b = ft_strjoin("Enemys: ", a);
	free(a);
	if (c->width < (SIZE * 15))
	{
		w = (c->width / 2) - (SIZE / 2);
		h = (c->height + ((SIZE / 2) * 5) + 6);
	}
	else
	{
		w = (c->width / 2) - -(SIZE * 4) + (SIZE / 2);
		h = (c->height + SIZE) - 2;
	}
	mlx_string_put(c->mlx_ctx, c->root, w, h, 0xFFFFFF, b);
	free(b);
}

void	coins_text(t_ctx *c)
{
	char	*a;
	char	*b;
	int		w;
	int		h;

	a = ft_itoa(c->player->coins_collected);
	b = ft_strjoin("Coins: ", a);
	free(a);
	if (c->width < (SIZE * 15))
	{
		w = (c->width / 2) - (SIZE / 2);
		h = (c->height + ((SIZE / 2)) + 6);
	}
	else
	{
		w = (c->width / 2) - (SIZE * 4) - (SIZE / 2);
		h = (c->height + SIZE) - 2;
	}
	mlx_string_put(c->mlx_ctx, c->root, w, h, 0xFFFFFF, b);
	free(b);
}
