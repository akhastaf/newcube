/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:05:00 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/07 14:08:01 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_H
# define LOAD_H

# include "structs.h"

void	load_file(char *path);
void	tozero_tkn(void);
void	treat_element(char *element);
void	treat_no(char *s);
void	treat_so(char *s);
void	treat_we(char *s);
void	treat_ea(char *s);
void	treat_s(char *s);
void	treat_f(char *s);
void	treat_c(char *s);
void	treat_r(char *s);
void	check_before_map(void);
void	treat_m(char *element);
int		empty_line(char *line);
void	fill_spaces(char *str, int s, int e);
void	adjust_map(void);
void	verify_map(void);
void	verify_player(void);
void	get_player(void);
void	chcek_player(int nop);
int		get_color(int r, int g, int b);
t_color	treat_color(char **s);
void	get_player_pos(char c);
void	check_map(void);
#endif
