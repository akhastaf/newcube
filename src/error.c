/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:01 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/13 20:37:24 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_error(char *str)
{
	if (!g_tkn.l)
	{
		free(g_file.line);
		while ((gnl(g_file.fd, &g_file.line)) > 0)
			free(g_file.line);
		free(g_file.line);
		close(g_file.fd);
	}
	if (g_tkn.no)
		free(g_game.tex[N_NO].path);
	if (g_tkn.so)
		free(g_game.tex[N_SO].path);
	if (g_tkn.we)
		free(g_game.tex[N_WE].path);
	if (g_tkn.ea)
		free(g_game.tex[N_EA].path);
	if (g_tkn.s)
		free(g_game.s_path);
	if (g_tkn.map)
		free_map();
	write_exit(str);
}

void	write_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	exit_error(char *s)
{
	if (g_tkn.img)
		mlx_destroy_image(g_game.m_ptr, g_img.img);
	if (g_tkn.win)
	{
		mlx_clear_window(g_game.m_ptr, g_game.w_ptr);
		mlx_destroy_window(g_game.m_ptr, g_game.w_ptr);
	}
	if (g_tkn.map)
		free_map();
	if (g_tkn.ea && g_tkn.no && g_tkn.we && g_tkn.so && g_tkn.s)
		free_paths();
	if (g_tkn.sp)
		free(g_game.sp);
	if (g_tkn.ray)
		free(g_rays);
	write_exit(s);
}
