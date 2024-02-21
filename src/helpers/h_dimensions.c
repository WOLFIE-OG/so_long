/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_dimensions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:02:18 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 17:45:32 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	get_height(t_ctx *c)
{
	return (ft_strarraylen(c->map->data));
}

int	get_width(t_ctx *c)
{
	return (ft_strlen_n(c->map->data[0]));
}
