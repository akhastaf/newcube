/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:40:47 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 19:58:23 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	treat_m(char *element)
{
	char **temp;

	if (g_game.map.map == NULL)
	{
		check_before_map();
		g_game.map.map = malloc(sizeof(char *));
		g_game.map.map[0] = ft_strdup(element);
		g_game.map.h = 1;
		g_game.map.w = ft_strlen(element);
		g_tkn.map = 1;
	}
	else
	{
		temp = g_game.map.map;
		g_game.map.map = malloc((g_game.map.h + 1) * sizeof(char *));
		ft_memcpy(g_game.map.map, temp, sizeof(char *) * g_game.map.h);
		free(temp);
		g_game.map.map[g_game.map.h] = ft_strdup(element);
		g_game.map.h += 1;
		g_game.map.w = BIGGER((int)ft_strlen(element), g_game.map.w);
	}
}

void	adjust_map(void)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = malloc(g_game.map.h * sizeof(char *));
	while (i < g_game.map.h)
	{
		new[i] = malloc(g_game.map.w + 1);
		ft_memcpy(new[i], g_game.map.map[i], ft_strlen(g_game.map.map[i]));
		fill_spaces(new[i], ft_strlen(g_game.map.map[i]), g_game.map.w);
		i++;
	}
	i = 0;
	while (i < g_game.map.h)
		free(g_game.map.map[i++]);
	free(g_game.map.map);
	g_game.map.map = new;
}

void	check_before_map(void)
{
	if (g_tkn.no == 0 || g_tkn.so == 0 || g_tkn.we == 0 || g_tkn.ea == 0
			|| g_tkn.s == 0 || g_tkn.f == 0 || g_tkn.c == 0 || g_tkn.r == 0)
		load_error("Error\nNot all elements defined above the map in <cub>");
}
