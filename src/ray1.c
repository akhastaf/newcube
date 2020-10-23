#include "../include/cub3d.h"


void    cast_all_rays()
{
    int     i;
    float   ray_angle;

    i = 0;
    ray_angle = g_player.rotation_angle - (FOV / 2);
    while (i < g_game.win_w)
    {
        g_rays[i].angle = ray_angle;
        cast_ray(i);
        ray_angle += FOV / g_game.win_w;
        i++;
    }
    
}

void    render_rays()
{
    int i;
    t_line ray;

    ray.color = 0xFF0000;
    i = 0;
    while (i < g_game.win_w)
    {
        copy_pos(&(ray.pos), g_player.pos);
        ray.pos.x *= SCALE;
        ray.pos.y *= SCALE;
        ray.d = g_rays[i].dist * SCALE;
        ray.alpha = g_rays[i].angle;
        if (ray.pos.x <= g_game.win_w && ray.pos.y <= g_game.win_h)
            draw_line(ray);
        i++;
    }
}

void    init_horz(int id)
{
    g_horz.hit = 0;
    g_horz.wall.x = 0;
    g_horz.wall.y = 0;
    g_horz.step.y = TILE_SIZE;
    g_horz.step.y *= (g_rays[id].ray_d ? 1 : -1);
    g_horz.step.x = g_horz.step.y / tan(g_rays[id].angle);
    g_horz.inter.y = floor(g_player.pos.y / TILE_SIZE) * TILE_SIZE;
    g_horz.inter.y += (g_rays[id].ray_d ? TILE_SIZE : 0);
    g_horz.inter.y += (g_rays[id].ray_up ? -1 : 0);
    g_horz.inter.x = g_player.pos.x + ((g_horz.inter.y - g_player.pos.y) / tan(g_rays[id].angle));
    g_horz.next.x = g_horz.inter.x;
    g_horz.next.y = g_horz.inter.y;
}

void cast_horz(int id)
{
    // int check;

    init_horz(id);
    // check = g_rays[id].ray_d ? 0 : -1;
    while ((g_horz.next.x >= 0 && g_horz.next.x <= g_game.map.w * TILE_SIZE) && (g_horz.next.y >= 0 && g_horz.next.y <= g_game.map.h * TILE_SIZE))
    {
        if (is_wall(g_horz.next.x, g_horz.next.y))
        {
            g_horz.hit = 1;
            g_horz.wall.x = g_horz.next.x;
            g_horz.wall.y = g_horz.next.y;
            // set_pos(&(g_horz.wall), g_horz.next.x, g_horz.next.y);
            break;
        }
        else
        {
            g_horz.next.x += g_horz.step.x;
            g_horz.next.y += g_horz.step.y;
        }
    };
}
void    init_vert(int id)
{
    g_vert.hit = 0;
    g_vert.wall.x = 0;
    g_vert.wall.y = 0;
    g_vert.step.x = TILE_SIZE;
    g_vert.step.x *= (g_rays[id].ray_l ? -1 : 1);
    g_vert.step.y = g_vert.step.x * tan(g_rays[id].angle);
    g_vert.inter.x = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
    g_vert.inter.x += (g_rays[id].ray_r ? TILE_SIZE : 0);
    g_vert.inter.x += (g_rays[id].ray_l ? -1 : 0);
    g_vert.inter.y = g_player.pos.y + ((g_vert.inter.x - g_player.pos.x) * tan(g_rays[id].angle));
    g_vert.next.x = g_vert.inter.x;
    g_vert.next.y = g_vert.inter.y;
}
void cast_vert(int id)
{
    // int check;
    
    init_vert(id);
    //check = g_rays[id].ray_r ? 0 : -1;
    while ((g_vert.next.x >= 0 && g_vert.next.x <= g_game.map.w * TILE_SIZE) && (g_vert.next.y >= 0 && g_vert.next.y <= g_game.map.h * TILE_SIZE))
    {
        if (is_wall(g_vert.next.x, g_vert.next.y))
        {
            g_vert.hit = 1;
            g_vert.wall.x = g_vert.next.x;
            g_vert.wall.y = g_vert.next.y;
            //set_pos(&(g_vert.wall), g_vert.next.x, g_vert.next.y);
            break;
        }
        else
        {
            g_vert.next.x += g_vert.step.x;
            g_vert.next.y += g_vert.step.y;
        }
    }
}

void cast_ray(int id)
{
    g_rays[id].angle = normalize_angle(g_rays[id].angle);
    g_rays[id].ray_d = ((g_rays[id].angle > 0 && g_rays[id].angle < M_PI)? 1 : 0);
    g_rays[id].ray_up = !g_rays[id].ray_d;
    g_rays[id].ray_r = ((g_rays[id].angle < M_PI * 0.5 || g_rays[id].angle > 1.5 * M_PI) ? 1 : 0);    
    g_rays[id].ray_l = !g_rays[id].ray_r;
    cast_horz(id);
    cast_vert(id);
    g_horz.dist = g_horz.hit ? distance(g_player.pos.x, g_player.pos.y, g_horz.wall.x, g_horz.wall.y) : MAX_INT;
    g_vert.dist = g_vert.hit ? distance(g_player.pos.x, g_player.pos.y, g_vert.wall.x, g_vert.wall.y) : MAX_INT;
    if (g_vert.dist < g_horz.dist)
    {
        g_rays[id].dist = g_vert.dist;
        set_pos(&(g_rays[id].wall_hit), g_vert.wall.x, g_vert.wall.y);
        g_rays[id].vert_hit = 1;
    }
    else
    {
        g_rays[id].dist = g_horz.dist;
        set_pos(&(g_rays[id].wall_hit), g_horz.wall.x, g_horz.wall.y);
        g_rays[id].vert_hit = 0;
    }
}
