/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:05:26 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/12 14:34:43 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render(void)
{
	render_wall();
	render_all_sp();
}

void	update(void)
{
	move_player();
	cast_all_rays();
	update_sp();
}

int		main_loop(void)
{
	clear_image();
	update();
	render();
	mlx_put_image_to_window(g_game.m_ptr, g_game.w_ptr, g_img.img, 0, 0);
	return (0);
}
