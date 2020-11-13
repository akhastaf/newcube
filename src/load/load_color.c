/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:40:40 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/12 20:46:12 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void		treat_f(char *s)
{
	t_color	color;

	color = treat_color(&s);
	if (color.r < 0 || color.r > 255 || color.g < 0
			|| color.g > 255 || color.b < 0 || color.b > 255)
		load_error("Error\nColors are invalid");
	skip_digit(&s);
	skip_spaces(&s);
	if (*s)
		load_error("Error\nNo value assigned to F element");
	g_game.floor = get_color(color.r, color.g, color.b);
	g_tkn.f += 1;
	if (g_tkn.f == 2)
		load_error("Error\nMore than one F detected in <cub> file");
}

void		treat_c(char *s)
{
	t_color color;

	color = treat_color(&s);
	if (color.r < 0 || color.r > 255 || color.g < 0
			|| color.g > 255 || color.b < 0 || color.b > 255)
		load_error("Error\nColors are invalid");
	skip_digit(&s);
	skip_spaces(&s);
	if (*s)
		load_error("Error\nNo value assigned to C element 3\n");
	g_game.ceil = get_color(color.r, color.g, color.b);
	g_tkn.c += 1;
	if (g_tkn.c == 2)
		load_error("Error\nMore than one C detected in <cub> file");
}

int			get_color(int r, int g, int b)
{
	r <<= 16;
	g <<= 8;
	return (r + g + b);
}

t_color		treat_color(char **s)
{
	t_color	color;
	int		i;

	i = 0;
	while (i < 3)
	{
		if (i != 0)
			skip_digit(&(*s));
		skip_spaces(&(*s));
		if (**s != ',' && i != 0)
			load_error("Error\nNo value assigned to color element\n");
		else if (**s == ',' && i != 0)
			(*s)++;
		skip_spaces(&(*s));
		if (!ft_isdigit(**s))
			load_error("Error\nNo value assigned to color element\n");
		if (i == 0)
			color.r = ft_atoi(*s);
		else if (i == 1)
			color.g = ft_atoi(*s);
		else if (i == 2)
			color.b = ft_atoi(*s);
		i++;
	}
	return (color);
}
