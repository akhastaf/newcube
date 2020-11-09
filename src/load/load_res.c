/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:40:49 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 09:01:24 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	treat_r(char *s)
{
	skip_spaces(&s);
	g_game.win_w = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	if (!ft_isdigit(*s))
		load_error("Error\nR not define probably element");
	g_game.win_h = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	if (*s)
		load_error("Error\nR not define probably element");
	g_tkn.r += 1;
	if (g_tkn.r == 2)
		load_error("Error\nMore  than one R detected in <cub> file");
	if (g_game.win_h <= 0 || g_game.win_w <= 0)
		load_error("Error\nR not define probably element");
	if (g_game.win_h > 1440)
		g_game.win_h = 1440;
	if (g_game.win_w > 2560)
		g_game.win_w = 2560;
}
