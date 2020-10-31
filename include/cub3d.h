#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include "mlx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <errno.h>

extern int errno;

# define MAX_INT 2147483647

#define N_NO  0
#define N_WE  1
#define N_EA  2
#define N_SO  3

#define FALSE 0
# define TRUE 1

# define SCALE 0.1

# define EVENT_KEYDOWN 2
# define EVENT_KEYUP 3
# define EVENT_EXIT 17
# define EXIT_SUCCESS 0
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define ESC_KEY 53

# define ANGLE_S    (8 * (M_PI / 180))
# define SPEED 8
# define FOV (60 * (M_PI / 180))

# define TILE_SIZE 64

#define IS_MAP_ELEMENT(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E' || x == '2' || x == '1' || x == '0' || x == ' ')
#define IS_ZSP(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E' || x == '2' || x == '0')
#define IS_P(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E')

typedef struct s_pos
{
    float   x;
    float   y;
}   t_pos;

typedef struct s_rec
{
    t_pos pos;
    t_pos size;
    int color;
} t_rec;

typedef struct s_line
{
    t_pos pos;
    float alpha;
    float   d;
    int color;
}   t_line;

typedef struct s_cercle
{
    t_pos pos;
    float   r;
    int color;
}   t_cercle;

typedef struct  s_img {
    void        *img;
    char        *addr;
    int         bpp;
    int         length;
    int         e;
}    t_img;

typedef struct	s_tkn
{
	char map;
	char no;
	char so;
	char we;
	char ea;
	char r;
	char s;
	char f;
	char c;
}				t_tkn;

typedef     struct s_color
{
    int     r;
    int     g;
    int     b;
}              t_color;




typedef struct s_map
{
    char **map;
	int w;
	int h;
}   t_map;

typedef struct	s_sp
{
    t_pos       pos;
	void		*ptr;
	int			*data;
	// t_pos       s;
	float		distance;
}				t_sp;

typedef struct  s_inter
{
    t_pos   next;
    t_pos   step;
    t_pos   inter;
    int     hit;
    t_pos   wall;
    float   dist;
}               t_inter;

typedef struct  s_ray
{
    float   angle;
    t_pos   wall_hit;
    float   dist;
    int     vert_hit;
    int     ray_d;
    int     ray_up;
    int     ray_r;
    int     ray_l;
}               t_ray;

typedef struct s_tex
{
    t_img   img;
    char    *path;
    int     w;
    int     h;
    float   offset_x;
    float   offset_y;
}       t_tex;

typedef struct s_player 
{
    t_pos pos;
    float rotation_angle;
    int turn_direction;
    int walk_direction;
    float move_speed;
    float angle_speed;
}   t_player;

typedef struct s_game
{
    // Minilibx
    void    *m_ptr;
    void    *w_ptr;
    char    *title;
    // Map properties
	t_map   map;
	//	Textures
	t_tex   tex[4];
    // Sprites
    char    *s_path;
    t_sp    *sp;
    int     sp_num;
	// Window resolution
	int win_w;
	int win_h;
	// Colors
	int floor;
	int ceil;
}   t_game;

t_player    g_player;
t_game      g_game;
t_img       g_img;
t_ray       *g_rays;
t_inter     g_horz;
t_inter     g_vert;

t_tkn       g_tkn;

// Load file
void load_file(char *path);
void tozero_tkn();
// void treat_line(char *line);

void treat_element(char *element);
void treat_no(char *s);
void treat_so(char *s);
void treat_we(char *s);
void treat_ea(char *s);
void treat_s(char *s);
void treat_f(char *s);
void treat_c(char *s);
void treat_r(char *s);
void check_before_map();
void treat_m(char *element);
int empty_line(char *line);
void fill_spaces(char *str, int s, int e);
void adjust_map();
void verify_map();
void verify_player();
void get_player();

// Game
void    init(void);
int     exit_game();
void exit_error(char *s);
void    process_input(void);
void    setup();
void    update();
void    render();
int     main_loop();

int key_down(int key);
int key_up(int key);

// Utils
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void    write_exit(char *s);
int     bigger(int a, int b);
void    skip_spaces(char **s);
int     spaces(char *s);
void	skip_digit(char **s);
t_pos    set_pos(t_pos *pos, float x, float y);
t_pos    copy_pos(t_pos *pos, t_pos s);
int     is_wall_at(t_pos pos);
float normalize_angle(float angle);
float distance(float x1, float y1, float x2, float y2);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
void	free_paths();
void	free_map();


// Draw
void            my_mlx_pixel_put(int x, int y, int color);
void    draw_rect(t_rec rec);
void    draw_line(t_line line);
void    draw_cercle(t_cercle cercle);

// Player
void    render_player();
void    move_player();

// Map
void    render_map();
int     hit_wall(t_pos pos);
int     is_wall(float x, float y);

// Ray
void    init_inter(t_inter *inter);
void    hor_inter(t_inter *horz, int i);
void    ver_inter(t_inter *vert, int i);
// void    ray_fill(t_inter *horz, t_inter *vert, int i);
void    cast_ray(int id);
void    cast_vert(int id);
void    cast_horz(int id);
void    init_horz(int id);
void    init_vert(int id);

// void cast_ray(int id);
void    cast_all_rays();
void    render_rays();


// Wall
void    render_wall();

// Textures
void    set_text();
void load_texture();
int  get_text_color(t_tex tex, int x, int y);
int     get_texture(int i);


// Sprites
void	sp_pos(void);
void	update_sp_d(void);
void	render_sp(int x, int y, int sp_size, int k);
void	init_sprite(int k, int *x_s, int *y_s);
void	sprites(void);
int     hit_sprite(t_pos pos);
void		sp_count();


// Save
void	save();
void	int_in_char(unsigned char *str, int value);
int		write_header(int fd, unsigned int fd_size);
int		write_data(int fd, unsigned int pad_byte_row);
void	screen_shot(void);

// GNL
int		gnl(int fd, char **line);
#endif