/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:22:03 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/05 13:43:28 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(void)
{
	int i;

	i = 0;
	while (i < g_game.map.h)
	{
		free(g_game.map.map[i]);
		i++;
	}
	free(g_game.map.map);
}
