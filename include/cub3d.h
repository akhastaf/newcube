#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include "mlx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

#define N_NO  0
#define N_WE  1
#define N_EA  2
#define N_SO  3

# define SCALE 0.2

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
# define ROT_ANGLE   (8 * (M_PI / 180))
# define SPEED 10

# define TILE_SIZE 64

#define IS_MAP_ELEMENT(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E' || x == '2' || x == '1' || x == '0')
#define IS_ZSP(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E' || x == '2')
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
	void		*ptr;
	int			*data;
	t_pos       s;
	float		distance;
}				t_sp;

typedef struct  s_ray
{
    t_pos   pos;
    float   angle;
    float   wall_hitx;
    float   wall_hity;
    float   distance;
    int     wall_hitcontent;
    int     vertical_hit;
    int     facing_down;
    int     facing_up;
    int     facing_right;
    int     facing_left;
}   t_ray;


typedef struct s_tex
{
    t_img   img;
    char    *path;
    int     w;
    int     h;
    //float   offset_x;
    //float   offset_y;
}       t_tex;

typedef struct s_player 
{
    t_pos pos;
    float rotation_angle;
    float move_speed;
    float angle_speed;
    int turn_direction;
    int walk_direction;
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
    t_sp    sp[100];
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


int		gnl(int fd, char **line);

#endif