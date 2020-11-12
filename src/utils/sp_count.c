/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:27:12 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/10 18:34:45 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sp_count(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_game.map.w)
	{
		j = 0;
		while (j < g_game.map.h)
		{
			if (g_game.map.map[j][i] == '2')
				g_game.sp_num++;
			j++;
		}
		i++;
	}
}
