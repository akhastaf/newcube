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
            rec.pos.x = y * TILE_SIZE * SCALE;
            rec.pos.y = x * TILE_SIZE * SCALE;
            draw_rect(rec);
            x++;
        }
        y++;
    }
}

int     hit_wall(t_pos pos)
{
    float   index_x;
    float   index_y;
    
    // if (pos.x < 0 || pos.x > g_game.win_w || pos.y < 0 || pos.y > g_game.win_h)
    //     return 1;
    index_x = floor(pos.x / TILE_SIZE);
    index_y = floor(pos.y / TILE_SIZE);
    return (g_game.map.map[(int)index_y][(int)index_x] == '1' ? 1 : 0);
}