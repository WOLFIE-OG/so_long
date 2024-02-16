/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 14:39:58 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	*lps(t_ctx *c, char *n, int w, int h)
{
	void	*i;

	i = mlx_xpm_file_to_image(c->mlx_ctx, n, &w, &h);
	if (!i)
		exit(1);
	ft_printf("Loaded: %s\n", n);
	free(n);
	return (i);
}

static void	sprites(t_ctx *ctx)
{
	t_player_sprites	*s;
	int					w;
	int					h;
	char				*dir;

	dir = "./res/tex/plr/";
	w = 30;
	h = 30;
	s = (t_player_sprites *)malloc(sizeof(t_player_sprites));
	if (!s)
		exit(1);
	s->down_alt = lps(ctx, ft_strjoin(dir, "down_alt.xpm"), w, h);
	s->down = lps(ctx, ft_strjoin(dir, "down.xpm"), w, h);
	s->idle = lps(ctx, ft_strjoin(dir, "idle.xpm"), w, h);
	s->left_alt = lps(ctx, ft_strjoin(dir, "left_alt.xpm"), w, h);
	s->left = lps(ctx, ft_strjoin(dir, "left.xpm"), w, h);
	s->right_alt = lps(ctx, ft_strjoin(dir, "right_alt.xpm"), w, h);
	s->right = lps(ctx, ft_strjoin(dir, "right.xpm"), w, h);
	s->up_alt = lps(ctx, ft_strjoin(dir, "up_alt.xpm"), w, h);
	s->up = lps(ctx, ft_strjoin(dir, "up.xpm"), w, h);
	ctx->player->sprites = s;
}

static void	player(t_ctx *ctx)
{
	t_player			*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		exit(1);
	player->x = 0;
	player->y = 0;
	player->direction = '0';
	player->is_alt = 0;
	ctx->player = player;
	ft_printf("Created player\n");
}

void	init_player(t_ctx *ctx)
{
	player(ctx);
	sprites(ctx);
}
