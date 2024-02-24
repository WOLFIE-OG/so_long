/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:52:59 by otodd             #+#    #+#             */
/*   Updated: 2024/02/24 23:02:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	put_img(t_ctx *c, t_img *img)
{
	t_vector2	*pos;

	pos = c->player->pos;
	put_buf(c, img, pos->x, pos->y);
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
