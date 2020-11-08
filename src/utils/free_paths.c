/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:22:56 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/05 13:43:53 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_paths(void)
{
	free(g_game.s_path);
	free(g_game.tex[N_NO].path);
	free(g_game.tex[N_SO].path);
	free(g_game.tex[N_WE].path);
	free(g_game.tex[N_EA].path);
}
