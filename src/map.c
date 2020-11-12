/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:14 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:04 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_wall(void)
{
	t_wall	wall;
	int		i;
	int		j;

	i = 0;
	while (i < g_game.win_w)
	{
		init_wall(i, &wall);
		j = 0;
		while (j < g_game.win_h)
		{
			if (j < wall.top)
				wall.color = g_game.ceil;
			else if (j < wall.top + wall.strip_h)
				cal_wall(j, &wall);
			else if (j > wall.top + wall.strip_h)
				wall.color = g_game.floor;
			my_mlx_pixel_put(i, j, wall.color);
			j++;
		}
		i++;
	}
}

void	init_wall(int i, t_wall *wall)
{
	wall->t = get_texture(i);
	wall->dist = (g_game.win_w / 2) / tan(FOV / 2);
	wall->correct_dist = g_rays[i].dist *
		cos(g_rays[i].angle - g_player.rot_angle);
	wall->strip_h = (TILE_SIZE / wall->correct_dist) * wall->dist;
	wall->top = (g_game.win_h / 2) - (wall->strip_h / 2);
	if (g_rays[i].vert_hit)
		g_game.tex[wall->t].offset_x = (int)g_rays[i].wall_hit.y % TILE_SIZE;
	else
		g_game.tex[wall->t].offset_x = (int)g_rays[i].wall_hit.x % TILE_SIZE;
}

void	cal_wall(int j, t_wall *wall)
{
	g_game.tex[wall->t].offset_y = (j + ((wall->strip_h / 2)
				- (g_game.win_h / 2)))
		* ((float)(g_game.tex[wall->t].h) / (float)wall->strip_h);
	if (g_game.tex[wall->t].offset_y >= g_game.win_h)
		g_game.tex[wall->t].offset_y = g_game.win_h - 1;
	else
		g_game.tex[wall->t].offset_y = g_game.tex[wall->t].offset_y;
	wall->color = get_text_color(g_game.tex[wall->t],
			g_game.tex[wall->t].offset_x, g_game.tex[wall->t].offset_y);
}
