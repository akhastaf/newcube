/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palyer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:19 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 14:19:24 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(void)
{
	t_pos pos;
	float step;

	step = g_player.walk_direction * SPEED;
	g_player.rot_angle += g_player.turn_direction * ANGLE_S;
	pos.x = g_player.pos.x + cos(g_player.rot_angle) * step;
	pos.y = g_player.pos.y + sin(g_player.rot_angle) * step;
	if (g_player.x_walk_direction)
	{
		pos.x = g_player.pos.x + cos(g_player.rot_angle + M_PI_2) * step;
		pos.y = g_player.pos.y + sin(g_player.rot_angle + M_PI_2) * step;
	}
	if (!hit_wall(pos) && !hit_sprite(pos))
		set_pos(&(g_player.pos), pos.x, pos.y);
}
