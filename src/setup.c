/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:29 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/12 14:37:56 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init(void)
{
	g_game.m_ptr = mlx_init();
	if (!g_game.m_ptr)
		exit_error("Error\nfaild to init mlx");
	g_tkn.mlx = 1;
	g_game.w_ptr = mlx_new_window(g_game.m_ptr,
			g_game.win_w,
			g_game.win_h, "Cub3D");
	if (!g_game.w_ptr)
		exit_error("Error\nfaild to init windows");
	g_tkn.win = 1;
	g_img.img = mlx_new_image(g_game.m_ptr, g_game.win_w, g_game.win_h);
	if (!g_img.img)
		exit_error("Error\nfaild to init image");
	g_tkn.img = 1;
	g_img.addr = mlx_get_data_addr(g_img.img,
			&g_img.bpp,
			&g_img.length,
			&g_img.e);
	if (!g_img.addr)
		exit_error("Error\nfaild to init image");
}

int		exit_game(void)
{
	mlx_clear_window(g_game.m_ptr, g_game.w_ptr);
	mlx_destroy_window(g_game.m_ptr, g_game.w_ptr);
	free_map();
	free_paths();
	free(g_rays);
	free(g_game.sp);
	exit(0);
	return (0);
}

void	clear_image(void)
{
	t_rec r;

	r.pos.x = 0;
	r.pos.y = 0;
	r.size.x = g_game.win_w;
	r.size.y = g_game.win_h;
	r.color = 0x00FFFFFF;
	draw_rect(r);
}

void	process_input(void)
{
	mlx_hook(g_game.w_ptr, EVENT_KEYDOWN, 0, key_down, (void*)0);
	mlx_hook(g_game.w_ptr, EVENT_KEYUP, 0, key_up, (void*)0);
	mlx_hook(g_game.w_ptr, EVENT_EXIT, 0, exit_game, (void*)0);
}

void	setup(void)
{
	g_game.sp_num = 0;
	sp_count();
	set_text();
	if (!(g_rays = malloc(sizeof(t_ray) * g_game.win_w)))
		exit_error("Error\nallocation fails at rays");
	g_tkn.ray = 1;
	if (!(g_game.sp = malloc(sizeof(t_sp) * g_game.sp_num)))
		exit_error("Error\nallocation fails at sprites");
	g_tkn.sp = 1;
	get_sp();
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
	init();
	process_input();
	load_texture();
}
