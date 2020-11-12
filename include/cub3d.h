/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:04:22 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/12 14:52:39 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include "mlx.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include "load.h"
# include "structs.h"
# include "utils.h"
# include "key.h"

# define BUFFER_SIZE 32
# define MAX_INT 2147483647
# define N_NO  0
# define N_WE  1
# define N_EA  2
# define N_SO  3
# define FALSE 0
# define TRUE 1
# define ANGLE_S (8 * (M_PI / 180))
# define SPEED 8
# define FOV (60 * (M_PI / 180))
# define TILE_SIZE 64
# define IS_P(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E')
# define BIGGER(x, y) (x >= y ? x : y)

t_player	g_player;
t_game		g_game;
t_img		g_img;
t_ray		*g_rays;
t_inter		g_horz;
t_inter		g_vert;
t_tkn		g_tkn;

void		init(void);
int			exit_game(void);
void		exit_error(char *s);
void		process_input(void);
void		setup(void);
void		update(void);
void		render(void);
int			main_loop(void);
void		clear_image(void);
void		my_mlx_pixel_put(int x, int y, int color);
void		draw_rect(t_rec rec);
void		draw_line(t_line line);
void		draw_cercle(t_cercle cercle);
void		move_player(void);
int			hit_wall(t_pos pos);
int			is_wall(float x, float y);
void		init_inter(t_inter *inter);
void		hor_inter(t_inter *horz, int i);
void		ver_inter(t_inter *vert, int i);
void		cast_ray(int id);
void		cast_vert(int id);
void		cast_horz(int id);
void		init_horz(int id);
void		init_vert(int id);
void		init_cast_ray(int id);
void		cast_all_rays(void);
void		render_wall(void);
void		set_text(void);
void		load_texture(void);
int			get_text_color(t_tex tex, int x, int y);
int			get_texture(int i);
void		get_sp(void);
void		update_sp(void);
void		render_sp(int x, int y, int sp_s, int k);
void		init_sprite(int k, int *x_s, int *y_s);
void		render_all_sp(void);
int			hit_sprite(t_pos pos);
void		sp_count(void);
void		save(void);
void		write_header(int fd, unsigned int fd_size);
void		write_data(int fd, unsigned int pad);
void		write_pad(int fd, int pad);
void		screen_shot(void);
void		load_error(char *str);
void		init_wall(int i, t_wall *wall);
void		cal_wall(int j, t_wall *wall);
int			gnl(int fd, char **line);
#endif
