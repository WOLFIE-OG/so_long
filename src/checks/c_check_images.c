/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:18:23 by otodd             #+#    #+#             */
/*   Updated: 2024/03/11 16:36:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_sprites(t_ctx *c)
{
	int	i;

	i = 0;
	while (i < NUM_SPRITES)
	{
		if (!c->sprites[c->sprite_table[i].sprite])
			destroy(c, "A sprite failed to load!", true);
		i++;
	}
}
