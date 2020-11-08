/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:57:37 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/07 13:56:32 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	tozero_tkn(void)
{
	g_tkn.map = 0;
	g_tkn.no = 0;
	g_tkn.so = 0;
	g_tkn.we = 0;
	g_tkn.ea = 0;
	g_tkn.s = 0;
	g_tkn.f = 0;
	g_tkn.c = 0;
	g_tkn.r = 0;
	g_tkn.mlx = 0;
	g_tkn.win = 0;
	g_tkn.sp = 0;
	g_tkn.ray = 0;
	g_tkn.img = 0;
}

void	treat_element(char *element)
{
	int		i;

	i = spaces(element);
	if (element[i] == 'N' && element[i + 1] == 'O')
		treat_no(element + 2 + i);
	else if (element[i] == 'S' && element[i + 1] == 'O')
		treat_so(element + 2 + i);
	else if (element[i] == 'W' && element[i + 1] == 'E')
		treat_we(element + 2 + i);
	else if (element[i] == 'E' && element[i + 1] == 'A')
		treat_ea(element + 2 + i);
	else if (element[i] == 'R')
		treat_r(element + 1 + i);
	else if (element[i] == 'S')
		treat_s(element + 1 + i);
	else if (element[i] == 'F')
		treat_f(element + 1 + i);
	else if (element[i] == 'C')
		treat_c(element + 1 + i);
	else if (is_map_element(*element) && !(element[i] == 0 && g_tkn.map == 0))
		treat_m(element);
	else
		load_error("Error\n<cub> file isn't well defined");
}

int		empty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
		if (line[i] != ' ' || line[i] != '\t')
			return (0);
	if (g_tkn.map == 1)
		load_error("Error\nMap should be the last Element in the <cub> file");
	return (1);
}

void	fill_spaces(char *str, int s, int e)
{
	int		i;

	i = s;
	while (i < e)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = 0;
}

void	load_file(char *path)
{
	int		fd;
	char	*line;
	int		r;

	if (!ft_strnstr(path, ".cub", ft_strlen(path)))
		load_error("Error\nThe filetype isn't <cub>");
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		write(1, "Error\n", 6);
		write_exit(strerror(errno));
	}
	g_game.map.map = 0;
	while ((r = gnl(fd, &line)) >= 0)
	{
		if (!empty_line(line))
			treat_element(line);
		free(line);
		if (r == 0)
			break ;
	}
	adjust_map();
	verify_map();
	verify_player();
	get_player();
}
