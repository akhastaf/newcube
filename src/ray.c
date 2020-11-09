/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:21 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 08:37:47 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cast_all_rays(void)
{
	int		i;
	float	ray_angle;

	i = 0;
	ray_angle = g_player.rot_angle - (FOV / 2);
	while (i < g_game.win_w)
	{
		g_rays[i].angle = ray_angle;
		cast_ray(i);
		ray_angle += FOV / g_game.win_w;
		i++;
	}
}

void	init_cast_ray(int id)
{
	g_rays[id].angle = normalize_angle(g_rays[id].angle);
	if (g_rays[id].angle > 0 && g_rays[id].angle < M_PI)
		g_rays[id].ray_d = 1;
	else
		g_rays[id].ray_d = 0;
	g_rays[id].ray_up = !g_rays[id].ray_d;
	if (g_rays[id].angle < 0.5 * M_PI || g_rays[id].angle > 1.5 * M_PI)
		g_rays[id].ray_r = 1;
	else
		g_rays[id].ray_r = 0;
	g_rays[id].ray_l = !g_rays[id].ray_r;
}

void	cast_ray(int id)
{
	init_cast_ray(id);
	cast_horz(id);
	cast_vert(id);
	g_horz.dist = g_horz.hit ? distance(g_player.pos.x,
			g_player.pos.y, g_horz.wall.x, g_horz.wall.y) : MAX_INT;
	g_vert.dist = g_vert.hit ? distance(g_player.pos.x,
			g_player.pos.y, g_vert.wall.x, g_vert.wall.y) : MAX_INT;
	if (g_vert.dist < g_horz.dist)
	{
		g_rays[id].dist = g_vert.dist;
		set_pos(&(g_rays[id].wall_hit), g_vert.wall.x, g_vert.wall.y);
		g_rays[id].vert_hit = 1;
	}
	else
	{
		g_rays[id].dist = g_horz.dist;
		set_pos(&(g_rays[id].wall_hit), g_horz.wall.x, g_horz.wall.y);
		g_rays[id].vert_hit = 0;
	}
}
