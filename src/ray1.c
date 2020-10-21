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

void cast_horz(int id)
{
    t_pos step;
    t_pos inter;
    
    step.y = TILE_SIZE;
    step.y *= (g_rays[id].ray_d ? 1 : -1);
    step.x = step.y / tan(g_rays[id].angle);
    inter.y = floor(g_player.pos.y / TILE_SIZE) * TILE_SIZE;
    inter.y += (g_rays[id].ray_d ? TILE_SIZE : 0);
    inter.y += (g_rays[id].ray_up ? -1 : 0);
    inter.x = g_player.pos.x + ((inter.y - g_player.pos.y) / tan(g_rays[id].angle));
    
    g_horz.next.x = inter.x;
    g_horz.next.y = inter.y;
    while ((g_horz.next.x > 0 && g_horz.next.x < g_game.win_w) && (g_horz.next.y > 0 && g_horz.next.y < g_game.win_h))
    {
        if (hit_wall(g_horz.next))
        {
            g_horz.hit = 1;
            set_pos(&(g_horz.wall), g_horz.next.x, g_horz.next.y);
            break;
        }
        else
        {
            g_horz.next.x += step.x;
            g_horz.next.y += step.y;
        }
    };
}

void cast_vert(int id)
{
    t_pos step;
    t_pos inter;
    
    step.x = TILE_SIZE;
    step.x *= (g_rays[id].ray_l ? -1 : 1);
    step.y = step.x * tan(g_rays[id].angle);
    inter.x = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
    inter.x += (g_rays[id].ray_r ? TILE_SIZE : 0);
    inter.x += (g_rays[id].ray_l ? -1 : 0);
    inter.y = g_player.pos.y + ((inter.x - g_player.pos.x) * tan(g_rays[id].angle));
    g_vert.next.x = inter.x;
    g_vert.next.y = inter.y;
    while ((g_vert.next.x > 0 && g_vert.next.x < g_game.win_w) && (g_vert.next.y > 0 && g_vert.next.y < g_game.win_h))
    {
        if (hit_wall(g_vert.next))
        {
            g_vert.hit = 1;
            set_pos(&(g_vert.wall), g_vert.next.x, g_vert.next.y);
            break;
        }
        else
        {
            g_vert.next.x += step.x;
            g_vert.next.y += step.y;
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
