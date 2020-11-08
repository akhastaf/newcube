/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:35 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/05 14:23:13 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_texture(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		g_game.tex[i].img.img = mlx_xpm_file_to_image(g_game.m_ptr,
				g_game.tex[i].path,
				&g_game.tex[i].w,
				&g_game.tex[i].h);
		if (!g_game.tex[i].img.img)
			exit_error("Error\nfiled to load the texture");
		g_game.tex[i].img.addr = mlx_get_data_addr(g_game.tex[i].img.img,
				&g_game.tex[i].img.bpp,
				&g_game.tex[i].img.length,
				&g_game.tex[i].img.e);
		i++;
	}
}

int		get_text_color(t_tex tex, int x, int y)
{
	if (x >= 0 && x < tex.w && y >= 0 && y < tex.h)
	{
		return (*((int*)tex.img.addr + (y * tex.w + x)));
	}
	return (0);
}

void	set_text(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		g_game.tex[i].w = 64;
		g_game.tex[i].h = 64;
		i++;
	}
}

int		get_texture(int i)
{
	if (!g_rays[i].vert_hit)
		return (g_rays[i].ray_d ? N_SO : N_NO);
	else
		return (g_rays[i].ray_l ? N_WE : N_EA);
	return (0);
}
