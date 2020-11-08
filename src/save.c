/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:20:27 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/06 10:22:51 by akhastaf         ###   ########.fr       */
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

void	int_in_char(unsigned char *str, int value)
{
	int i;

	i = -1;
	while (++i < 4)
		str[i] = (unsigned char)(value >> (i * 8));
}

int		write_header(int fd, unsigned int fd_size)
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
	return (write(fd, header, 54));
}

int		write_data(int fd, unsigned int pad_br)
{
	const unsigned char zeroes[3] = {0, 0, 0};
	int					y;
	int					x;

	y = -1;
	while (++y < g_game.win_h)
	{
		x = -1;
		while (++x < g_game.win_w)
			if (write(fd, &((int*)g_img.addr)[y * g_game.win_w + x], 3)
			< 0)
				return (0);
		if (write(fd, &zeroes, pad_br) < 0)
			return (0);
	}
	return (1);
}

void	screen_shot(void)
{
	int				fd;
	unsigned int	size;
	unsigned int	pbr;
	unsigned int	pad_br;

	pbr = g_game.win_w * 3;
	pad_br = (4 - (pbr % 4)) % 4;
	size = 54 + (pbr + pad_br) * g_game.win_h;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
		S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
	{
		write(1, "Error\n", 7);
		exit_error(strerror(errno));
	}
	if (write_header(fd, size) < 0)
	{
		write(1, "Error\n", 7);
		exit_error(strerror(errno));
	}
	if (!write_data(fd, pad_br))
	{
		write(1, "Error\n", 7);
		exit_error(strerror(errno));
	}
	close(fd);
}
