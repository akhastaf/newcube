/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:40:42 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/07 13:57:15 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player(void)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < g_game.map.h)
	{
		while (++j < g_game.map.w)
		{
			if (is_map_element(g_game.map.map[i][j])
					|| g_game.map.map[i][j] == ' ')
			{
				if (IS_P(g_game.map.map[i][j]))
				{
					g_player.pos.x = j * TILE_SIZE + TILE_SIZE / 2;
					g_player.pos.y = i * TILE_SIZE + TILE_SIZE / 2;
					get_player_pos(g_game.map.map[i][j]);
					break ;
				}
			}
		}
		j = -1;
	}
}

void	verify_player(void)
{
	int		i;
	int		j;
	int		nop;

	i = -1;
	j = -1;
	nop = 0;
	while (++i < g_game.map.h)
	{
		while (++j < g_game.map.w)
		{
			if (is_map_element(g_game.map.map[i][j])
					|| g_game.map.map[i][j] == ' ')
			{
				if (IS_P(g_game.map.map[i][j]))
					nop++;
			}
			else
				load_error("Error\nBad character in map");
		}
		j = -1;
	}
	chcek_player(nop);
}

void	chcek_player(int nop)
{
	if (nop == 0)
		load_error("Error\nNo player detected in map");
	else if (nop > 1)
		load_error("Error\nMore than one player detected in map");
}

void	get_player_pos(char c)
{
	if (c == 'N')
		g_player.rot_angle = 3 * M_PI / 2;
	if (c == 'S')
		g_player.rot_angle = M_PI / 2;
	if (c == 'W')
		g_player.rot_angle = M_PI;
	if (c == 'E')
		g_player.rot_angle = 0;
}
