/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:32 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/12 14:52:24 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

void	get_sp(void)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < g_game.map.w)
	{
		j = 0;
		while (j < g_game.map.h)
		{
			if (g_game.map.map[j][i] == '2')
			{
				g_game.sp[k].pos.x = i * TILE_SIZE + TILE_SIZE / 2;
				g_game.sp[k].pos.y = j * TILE_SIZE + TILE_SIZE / 2;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	update_sp(void)
{
	int		i;
	int		j;
	t_sp	ech;

	i = -1;
	while (++i < g_game.sp_num)
		g_game.sp[i].distance = distance(g_game.sp[i].pos.x,
				g_game.sp[i].pos.y, g_player.pos.x, g_player.pos.y);
	i = 0;
	while (i < g_game.sp_num)
	{
		j = 0;
		while (j < g_game.sp_num - i - 1)
		{
			if (g_game.sp[j].distance < g_game.sp[j + 1].distance)
			{
				ech = g_game.sp[j];
				g_game.sp[j] = g_game.sp[j + 1];
				g_game.sp[j + 1] = ech;
			}
			j++;
		}
		i++;
	}
}

void	render_sp(int x, int y, int sp_s, int k)
{
	int c;
	int i;
	int j;
	int x_s;
	int y_s;

	init_sprite(k, &x_s, &y_s);
	i = -1;
	while (++i < sp_s)
	{
		if (x + i < 0 || x + i > g_game.win_w)
			continue;
		if (x + i < g_game.win_w)
			if (g_game.sp[k].distance >= g_rays[i + x].dist)
				continue;
		j = -1;
		while (++j < sp_s)
		{
			c = g_game.sp[k].data[x_s * (j * y_s / sp_s) + (i * x_s / sp_s)];
			if (c > 0x000000)
				if (((x + i) >= 0 && (x + i) < g_game.win_w) &&
						((y + j) >= 0 && (y + j) < g_game.win_h))
					my_mlx_pixel_put(x + i, y + j, c);
		}
	}
}

void	init_sprite(int k, int *x_s, int *y_s)
{
	int a;

	g_game.sp[k].ptr = mlx_xpm_file_to_image(g_game.m_ptr,
			g_game.s_path, x_s, y_s);
	if (g_game.sp[k].ptr == NULL)
		exit_error("Error\nthe sprite file can't be loaded");
	g_game.sp[k].data = (int *)mlx_get_data_addr(g_game.sp[k].ptr, &a, &a, &a);
}

void	render_all_sp(void)
{
	float	sp_angle;
	float	sp_size;
	float	x;
	float	y;
	int		k;

	k = -1;
	while (++k < g_game.sp_num)
	{
		sp_angle = atan2(g_game.sp[k].pos.y - g_player.pos.y,
				g_game.sp[k].pos.x - g_player.pos.x);
		while (sp_angle - (g_player.rot_angle) > M_PI)
			sp_angle -= 2 * M_PI;
		while (sp_angle - (g_player.rot_angle) < -M_PI)
			sp_angle += 2 * M_PI;
		if (g_game.win_h > g_game.win_w)
			sp_size = (g_game.win_h / g_game.sp[k].distance) * TILE_SIZE;
		else
			sp_size = (g_game.win_w / g_game.sp[k].distance) * TILE_SIZE;
		y = g_game.win_h / 2 - sp_size / 2;
		x = (sp_angle - (g_player.rot_angle))
			* g_game.win_w / (FOV)
			+ (g_game.win_w / 2 - sp_size / 2);
		render_sp(x, y, sp_size, k);
	}
}
