/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:25:18 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 14:18:02 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		hit_wall(t_pos pos)
{
	int		index_x;
	int		index_y;

	if (pos.x < 0 || pos.x > g_game.map.w * TILE_SIZE ||
			pos.y < 0 || pos.y > g_game.map.h * TILE_SIZE)
		return (1);
	index_x = floor((pos.x) / TILE_SIZE);
	index_y = floor((pos.y) / TILE_SIZE);
	if (g_player.walk_direction == 1 &&
			g_player.rot_angle >= M_PI && g_player.rot_angle <= 2 * M_PI)
		index_y = (floor((pos.y - 4)) / TILE_SIZE);
	if (g_player.walk_direction == 1 && g_player.rot_angle >= M_PI / 2
			&& g_player.rot_angle <= 1.5 * M_PI)
		index_x = (floor((pos.x - 4)) / TILE_SIZE);
	if (g_player.x_walk_direction == -1 && g_player.rot_angle >= M_PI
			&& g_player.rot_angle <= 2 * M_PI)
		index_x = (floor((pos.x - 4)) / TILE_SIZE);
	if (g_player.x_walk_direction == -1 && ((g_player.rot_angle >= 0
				&& g_player.rot_angle <= 0.5 * M_PI)
				|| (g_player.rot_angle >= 1.5 * M_PI
				&& g_player.rot_angle <= M_2_PI)))
		index_y = (floor((pos.y - 4)) / TILE_SIZE);
	if (g_game.map.map[(int)index_y][(int)index_x] == '1')
		return (1);
	return (0);
}

int		is_wall(float x, float y)
{
	float	index_x;
	float	index_y;

	if (x < 0 || x > g_game.map.w * TILE_SIZE || y < 0 ||
			y > g_game.map.h * TILE_SIZE)
		return (1);
	index_x = floor((x) / TILE_SIZE);
	index_y = floor((y) / TILE_SIZE);
	if (g_game.map.map[(int)index_y][(int)index_x] == '1' ||
			g_game.map.map[(int)index_y][(int)index_x] == ' ')
		return (1);
	return (0);
}

int		hit_sprite(t_pos pos)
{
	float	index_x;
	float	index_y;

	if (pos.x < 0 || pos.x > g_game.map.w * TILE_SIZE ||
			pos.y < 0 || pos.y > g_game.map.h * TILE_SIZE)
		return (1);
	index_x = floor(pos.x / TILE_SIZE);
	index_y = floor(pos.y / TILE_SIZE);
	return (g_game.map.map[(int)index_y][(int)index_x] == '2' ? 1 : 0);
}
