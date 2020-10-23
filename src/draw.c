#include "../include/cub3d.h"

void            my_mlx_pixel_put(int x, int y, int color)
{
    char    *dst;

    dst = g_img.addr + (y * g_img.length + x * (g_img.bpp / 8));
    *(unsigned int*)dst = color;
}

void    draw_rect(t_rec rec)
{
    float w, h, x;
    h = 0;
    x = rec.pos.x;
    while (h < rec.size.y)
    {
        w = 0;
        while (w < rec.size.x)
        {
            my_mlx_pixel_put(x, rec.pos.y, rec.color);
            x++;
            w++;
        }
        rec.pos.y++;
        x = rec.pos.x;
        h++;
    }
}

void    draw_line(t_line line)
{
    float i;
    float new_x;
    float new_y;

    i = 0;
    while (i < line.d)
    {
        new_x = line.pos.x + cos(line.alpha) * i;
        new_y = line.pos.y + sin(line.alpha) * i;
        my_mlx_pixel_put(new_x, new_y, line.color);
        i = i + 0.2;
    }
}

void    draw_cercle(t_cercle cercle)
{
    double i;
    float j;
    t_line l;
    
    i = 0.1;
    l.color = cercle.color;
    while (i < 360)
    {
        j = 0;
        l.alpha = i * M_PI / 180;
        while (j < cercle.r)
        {
            l.pos.x = cercle.pos.x;
            l.pos.y = cercle.pos.y;
            l.d = j;
            draw_line(l);
            j++;
        }
        i += 0.1;
    }
}