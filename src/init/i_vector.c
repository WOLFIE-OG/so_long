/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:03:49 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:02:06 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_vector2	*vector2(void)
{
	t_vector2	*tmp;

	tmp = malloc(sizeof(t_vector2));
	if (!tmp)
		return (NULL);
	tmp->x = 0;
	tmp->y = 0;
	return (tmp);
}
