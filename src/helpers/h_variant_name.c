/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_variant_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:50:47 by otodd             #+#    #+#             */
/*   Updated: 2024/03/04 17:23:38 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_variant_name(t_ctx *c)
{
	if (c->variant == CAT)
		c->variant_name = "cat";
	else if (c->variant == TABBY_CAT)
		c->variant_name = "t_cat";
	else if (c->variant == DEVIL)
		c->variant_name = "devil";
	else if (c->variant == DOG)
		c->variant_name = "dog";
	else if (c->variant == CAT_GIRL)
		c->variant_name = "c_girl";
	else
		c->variant_name = "cat";
}
