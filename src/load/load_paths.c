/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:40:51 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/06 14:49:15 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	treat_no(char *s)
{
	skip_spaces(&s);
	if (!*s)
		load_error("Error\nNo value assigned to NO element");
	g_game.tex[N_NO].path = ft_strdup(s);
	if (!g_game.tex[N_NO].path)
		load_error("Error\nThe allocation faild for NO");
	g_tkn.no += 1;
	if (g_tkn.no == 2)
		load_error("Error\nMore than one NO detected in <cub> file");
}

void	treat_so(char *s)
{
	skip_spaces(&s);
	if (!*s)
		load_error("Error\nNo value assigned to SO element");
	g_game.tex[N_SO].path = ft_strdup(s);
	if (!g_game.tex[N_SO].path)
		load_error("Error\nThe allocation faild for SO");
	g_tkn.so += 1;
	if (g_tkn.so == 2)
		load_error("Error\nMore than one SO detected in <cub> file");
}

void	treat_we(char *s)
{
	skip_spaces(&s);
	if (!*s)
		load_error("Error\nNo value assigned to WE element");
	g_game.tex[N_WE].path = ft_strdup(s);
	if (!g_game.tex[N_WE].path)
		load_error("Error\nThe allocation faild for WE");
	g_tkn.we += 1;
	if (g_tkn.we == 2)
		load_error("Error\nMore than one WE detected in <cub> file");
}

void	treat_ea(char *s)
{
	skip_spaces(&s);
	if (!*s)
		load_error("Error\nNo value assigned to EA element");
	g_game.tex[N_EA].path = ft_strdup(s);
	if (!g_game.tex[N_EA].path)
		load_error("Error\nThe allocation faild for EA");
	g_tkn.ea += 1;
	if (g_tkn.ea == 2)
		load_error("Error\nMore than one EA detected in <cub> file");
}

void	treat_s(char *s)
{
	skip_spaces(&s);
	if (!*s)
		load_error("Error\nNo value assigned to S element");
	g_game.s_path = ft_strdup(s);
	if (!g_game.s_path)
		load_error("Error\nThe allocation faild for the sprite path");
	g_tkn.s += 1;
	if (g_tkn.s == 2)
		load_error("Error\nMore than one S detected in <cub> file");
}
