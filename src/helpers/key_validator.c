/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:29:27 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 12:47:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_check(int key)
{
	int	c;
	int	keys[] = {
		KEY_UP,
		KEY_DOWN,
		KEY_LEFT,
		KEY_RIGHT,
		ESC
	};

	c = 5;
	while (c)
		if (key == keys[--c])
			return (1);
	return (0);
}