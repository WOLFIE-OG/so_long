/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:29:22 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 18:34:02 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map(t_ctx *c)
{
	if (c->map)
	{
		if (c->map->data)
		{
			ft_free_array(c->map->data, ft_strarraylen(c->map->data));
			free(c->map->data);
		}
		free(c->map);
	}
}
