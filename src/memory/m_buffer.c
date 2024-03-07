/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:52:59 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:10:21 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	put_img(t_ctx *c, t_img *img)
{
	put_buf(c, img, c->player->win_pos->x, c->player->win_pos->y);
}

void	put_buf(t_ctx *c, t_img *img, int x, int y)
{
	int	img_offset;
	int	buffer_offset;
	int	i;

	buffer_offset = y * c->buffer->size_line + x * (img->bpp / 8);
	img_offset = 0;
	i = 0;
	while (i < SIZE)
	{
		ft_memcpy(
			c->buffer->data + buffer_offset,
			img->data + img_offset,
			(img->bpp / 8) * SIZE
			);
		img_offset += img->size_line;
		buffer_offset += c->buffer->size_line;
		i++;
	}
}
