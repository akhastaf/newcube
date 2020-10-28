#include "../include/cub3d.h"

void    render_map()
{
    float x, y;
    t_rec rec;

    rec.size.y = TILE_SIZE * SCALE;
    rec.size.x = TILE_SIZE * SCALE;
    y = 0;
    while (y < g_game.map.w)
    {
        x = 0;
        while (x < g_game.map.h)
        {
            if(g_game.map.map[(int)x][(int)y] == '0')
                rec.color = 16777215;
            else if (g_game.map.map[(int)x][(int)y] == '1')
                rec.color = 0;
            else if (g_game.map.map[(int)x][(int)y] == '2')
                rec.color = 0x00fcf876;
            rec.pos.x = y * TILE_SIZE * SCALE;
            rec.pos.y = x * TILE_SIZE * SCALE;
            draw_rect(rec);
            x++;
        }
        y++;
    }
}


void    render_wall()
{
    float distance;
    float wall_strip_height;
    float top, j;
    float correct_distance;
    int i, t;
    int color;

    i = 0;
    while (i < g_game.win_w)
    {
        t = get_texture(i);
        distance = (g_game.win_w / 2) / tan(FOV / 2);
        correct_distance = g_rays[i].dist * cos(g_rays[i].angle - g_player.rotation_angle);
        wall_strip_height = (TILE_SIZE / correct_distance) * distance;
        top = (g_game.win_h / 2) - (wall_strip_height / 2);
        g_game.tex[t].offset_x = g_rays[i].vert_hit ? (int)g_rays[i].wall_hit.y % TILE_SIZE : (int)g_rays[i].wall_hit.x % TILE_SIZE;

        j = 0;
        while (j < g_game.win_h)
        {
            
            if (j < top)
                color = g_game.ceil;
            else if (j < top + wall_strip_height)
            {
                g_game.tex[t].offset_y =  (j + ((wall_strip_height / 2) - (g_game.win_h / 2))) * ((float)(g_game.tex[t].h) / (float)wall_strip_height);
                g_game.tex[t].offset_y = g_game.tex[t].offset_y >= g_game.win_h ? g_game.win_h - 1 : g_game.tex[t].offset_y;
                color = get_text_color(g_game.tex[t], g_game.tex[t].offset_x, g_game.tex[t].offset_y);
                // color = 0x00389393;
            }
            else if (j > top + wall_strip_height)
                color = g_game.floor;
            my_mlx_pixel_put(i, j, color);
            j++;
        }
        i++;
    }
}

int     hit_wall(t_pos pos)
{
    float   index_x;
    float   index_y;
    
    if (pos.x < 0 || pos.x > g_game.map.w * TILE_SIZE || pos.y < 0 || pos.y > g_game.map.h * TILE_SIZE)
        return 1;
    index_x = floor(pos.x / TILE_SIZE);
    index_y = floor(pos.y / TILE_SIZE);
    return (g_game.map.map[(int)index_y][(int)index_x] == '1' ? 1 : 0);
}

int     is_wall(float x, float y)
{
    float   index_x;
    float   index_y;
    
    if (x < 0 || x > g_game.map.w * TILE_SIZE || y < 0 || y > g_game.map.h * TILE_SIZE)
        return 1;
    index_x = floor(x / TILE_SIZE);
    index_y = floor(y / TILE_SIZE);
    return (g_game.map.map[(int)index_y][(int)index_x] == '1' ? 1 : 0);
}