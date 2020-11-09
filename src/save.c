/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:27 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 09:43:49 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	save(void)
{
	update();
	render();
	screen_shot();
	exit_game();
}

void	write_header(int fd, unsigned int fd_size)
{
	unsigned char	header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_in_char(header + 2, fd_size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_in_char(header + 18, g_game.win_w);
	int_in_char(header + 22, -g_game.win_h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	if (write(fd, header, 54) <= 0)
	{
		write(1, "Error\n", 7);
		exit_error(strerror(errno));
	}
}

void	write_data(int fd, unsigned int pad)
{
	int		y;
	int		x;

	y = -1;
	while (++y < g_game.win_h)
	{
		x = -1;
		while (++x < g_game.win_w)
		{
			if (write(fd, &((int*)g_img.addr)[y * g_game.win_w + x], 3)
					< 0)
			{
				write(1, "Error\n", 7);
				exit_error(strerror(errno));
			}
		}
		write_pad(fd, pad);
	}
}

void	write_pad(int fd, int pad)
{
	unsigned char	z;
	int				i;

	z = 0;
	i = -1;
	while (++i < pad)
	{
		if (write(fd, &z, 1) < 0)
		{
			write(1, "Error\n", 7);
			exit_error(strerror(errno));
		}
	}
}

void	screen_shot(void)
{
	int				fd;
	unsigned int	size;
	unsigned int	pbr;
	unsigned int	pad;

	pbr = g_game.win_w * 3;
	pad = (4 - (pbr % 4)) % 4;
	size = 54 + (pbr + pad) * g_game.win_h;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
					S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
	{
		write(1, "Error\n", 7);
		exit_error(strerror(errno));
	}
	write_header(fd, size);
	write_data(fd, pad);
	close(fd);
}
