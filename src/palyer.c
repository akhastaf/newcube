#include "../include/cub3d.h"

void    move_player()
{
    t_pos pos;
    float step;

    step = g_player.walk_direction * g_player.move_speed;
    g_player.rotation_angle += g_player.turn_direction * g_player.angle_speed;
    pos.x = g_player.pos.x + cos(g_player.rotation_angle) * step;
    pos.y = g_player.pos.y + sin(g_player.rotation_angle) * step;

    if (!hit_wall(pos))
        set_pos(&(g_player.pos), pos.x , pos.y);
}

void    render_player()
{
    t_cercle c;
    t_line l;

    l.d = 40 * SCALE;
    copy_pos(&l.pos, g_player.pos);
    l.alpha = g_player.rotation_angle;
    l.pos.x *= SCALE;
    l.pos.y *= SCALE;
    l.color = 0x0000FF00;
    c.color = 0x0000FF00;
    c.pos.x = g_player.pos.x * SCALE;
    c.pos.y = g_player.pos.y * SCALE;
    c.r = 4 * SCALE;

    draw_cercle(c);
    draw_line(l);
}