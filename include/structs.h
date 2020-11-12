/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:07:25 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/12 14:47:42 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_pos
{
	float		x;
	float		y;
}				t_pos;

typedef struct	s_rec
{
	t_pos		pos;
	t_pos		size;
	int			color;
}				t_rec;

typedef struct	s_line
{
	t_pos		pos;
	float		alpha;
	float		d;
	int			color;
}				t_line;

typedef struct	s_cercle
{
	t_pos		pos;
	float		r;
	int			color;
}				t_cercle;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			length;
	int			e;
}				t_img;

typedef struct	s_tkn
{
	char		map;
	char		no;
	char		so;
	char		we;
	char		ea;
	char		r;
	char		s;
	char		f;
	char		c;
	char		ray;
	char		sp;
	char		win;
	char		mlx;
	char		img;
}				t_tkn;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_wall
{
	float		dist;
	float		strip_h;
	float		correct_dist;
	float		top;
	int			t;
	int			color;
}				t_wall;

typedef struct	s_map
{
	char		**map;
	int			w;
	int			h;
}				t_map;

typedef struct	s_sp
{
	t_pos		pos;
	void		*ptr;
	int			*data;
	float		distance;
}				t_sp;

typedef struct	s_inter
{
	t_pos		next;
	t_pos		step;
	t_pos		inter;
	int			hit;
	t_pos		wall;
	float		dist;
}				t_inter;

typedef struct	s_ray
{
	float		angle;
	t_pos		wall_hit;
	float		dist;
	int			vert_hit;
	int			ray_d;
	int			ray_up;
	int			ray_r;
	int			ray_l;
}				t_ray;

typedef struct	s_tex
{
	t_img		img;
	char		*path;
	int			w;
	int			h;
	float		offset_x;
	float		offset_y;
}				t_tex;

typedef struct	s_player
{
	t_pos		pos;
	float		rot_angle;
	int			turn_direction;
	int			walk_direction;
	int			x_walk_direction;
}				t_player;

typedef struct	s_game
{
	void		*m_ptr;
	void		*w_ptr;
	char		*title;
	t_map		map;
	t_tex		tex[4];
	char		*s_path;
	t_sp		*sp;
	int			sp_num;
	int			win_w;
	int			win_h;
	int			floor;
	int			ceil;
}				t_game;
#endif
