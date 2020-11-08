/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:40:45 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/07 13:56:21 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	verify_map(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_game.map.w)
	{
		if ((g_game.map.map[0][i] != '1' && g_game.map.map[0][i] != ' ')
				|| (g_game.map.map[g_game.map.h - 1][i] != '1'
				&& g_game.map.map[g_game.map.h - 1][i] != ' '))
			load_error("Error\nIncorrect Map");
	}
	i = -1;
	while (++i < g_game.map.h)
	{
		if ((g_game.map.map[i][0] != '1' && g_game.map.map[i][0] != ' ')
				|| (g_game.map.map[i][g_game.map.w - 1] != '1'
				&& g_game.map.map[i][g_game.map.w - 1] != ' '))
			load_error("Error\nIncorrect Map");
	}
	check_map();
}

void	check_map(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < g_game.map.h - 1)
	{
		while (++j < g_game.map.w - 1)
		{
			if (is_zsp(g_game.map.map[i][j])
					&& (g_game.map.map[i - 1][j - 1] == ' '
						|| g_game.map.map[i - 1][j] == ' '
						|| g_game.map.map[i - 1][j + 1] == ' '
						|| g_game.map.map[i][j - 1] == ' '
						|| g_game.map.map[i][j + 1] == ' '
						|| g_game.map.map[i + 1][j - 1] == ' '
						|| g_game.map.map[i + 1][j] == ' '
						|| g_game.map.map[i + 1][j + 1] == ' '))
				load_error("Error\nMap should be rounded by 1");
		}
		j = 0;
	}
}
