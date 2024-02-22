/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_idle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:59:03 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 14:10:27 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	idle_check(t_ctx *c)
{
	time_t	c_time;
	double	t_diff;

	time(&c_time);
	t_diff = difftime(c_time, c->player->last_active_time);
	if (t_diff >= c->max_idle)
		c->player->is_tired = true;
	else
		c->player->is_tired = false;
}
