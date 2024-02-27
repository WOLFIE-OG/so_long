/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/27 10:48:07 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int arg_n, char **arg_a)
{
	t_ctx	*c;
	char	*name;	

	name = "map.ber";
	if (arg_n == 2)
		name = arg_a[1];
	c = init_main(name);
	c->game_running = 1;
	c->current_key = 0;
	mlx_loop_hook(c->mlx_ctx, update, c);
	mlx_hook(c->root, KeyPress, KeyPressMask, key_press_handler, c);
	mlx_hook(c->root, KeyRelease, KeyReleaseMask, key_release_handler, c);
	mlx_hook(c->root, DestroyNotify, 0, close_program, c);
	mlx_loop(c->mlx_ctx);
	destroy(c, "Exiting...", 0);
	return (0);
}
