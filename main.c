/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:57:42 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 20:03:47 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"



int		main(int ac, char **av)
{
	if (ac <= 1)
		write_exit("Error\nfile .cup argument is missing\n");
	if (ac > 3)
		write_exit("Error\ntoo many argument\n");
	if (ac >= 2)
		load_file(av[1]);
	setup();
	if (ac == 3)
	{
		if (!(ft_strcmp(av[2], "--save")))
			save();
		else
			exit_error("Error\nseccond argument unkown");
	}
	mlx_loop_hook(g_game.m_ptr, &main_loop, (void*)0);
	mlx_loop(g_game.m_ptr);
	//leakcheckfull();
	return (0);
}
