/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:19:51 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/10 18:24:21 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = g_img.addr + (y * g_img.length + x * (g_img.bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_rect(t_rec rec)
{
	float w;
	float h;
	float x;

	h = 0;
	x = rec.pos.x;
	while (h < rec.size.y)
	{
		w = 0;
		while (w < rec.size.x)
		{
			my_mlx_pixel_put(x, rec.pos.y, rec.color);
			x++;
			w++;
		}
		rec.pos.y++;
		x = rec.pos.x;
		h++;
	}
}

void	draw_line(t_line line)
{
	float i;
	float new_x;
	float new_y;

	i = 0;
	while (i < line.d)
	{
		new_x = line.pos.x + cos(line.alpha) * i;
		new_y = line.pos.y + sin(line.alpha) * i;
		my_mlx_pixel_put(new_x, new_y, line.color);
		i = i + 0.2;
	}
}
