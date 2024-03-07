/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:36 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:24:14 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_ctx	*init_main(char *name, int variant)
{
	t_ctx		*c;

	c = malloc(sizeof(t_ctx));
	if (!c)
		destroy(c, ft_strdup("Failed to alloc ctx!"), true);
	c->sprites = malloc(sizeof(t_img *) * NUM_SPRITES);
	if (!c->sprites)
		destroy(c, ft_strdup("Failed to alloc sprites!"), true);
	init_sprite_table(c);
	c->mlx_ctx = NULL;
	c->root = NULL;
	c->buffer = NULL;
	c->world = NULL;
	c->player = NULL;
	c->map = NULL;
	c->variant = variant;
	ft_printf("["BBLU"CTX"RESET"]		Created CTX\n");
	init_map(c, name);
	init_mlx(c, name);
	init_player(c);
	init_world(c);
	check_sprites(c);
	init_ui(c);
	return (c);
}
