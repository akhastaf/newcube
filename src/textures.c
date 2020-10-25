#include "../include/cub3d.h"

void load_texture()
{
    int i;

    i = 0;
    while (i < 4)
    {
        g_game.tex[i].img.img = mlx_xpm_file_to_image(g_game.m_ptr, g_game.tex[i].path, &g_game.tex[i].w, &g_game.tex[i].h);
        if (!g_game.tex[i].img.img)
            write_exit("Error\nfiled to load the texture");
        g_game.tex[i].img.addr = mlx_get_data_addr(g_game.tex[i].img.img, &g_game.tex[i].img.bpp, &g_game.tex[i].img.length, &g_game.tex[i].img.e);
        i++;
    }
}

int  get_text_color(t_tex tex, int x, int y)
{
    if (x >= 0 && x < tex.w && y >= 0 && y < tex.h)
    {
        return(*((int*)tex.img.addr + (y * tex.w + x )));
    }
    return 0;
}
void    set_text()
{
    int i;

    i = 0;
    while (i < 4)
    {
        g_game.tex[i].w = 64;
        g_game.tex[i].h = 64;
        i++;
    }
}

int     get_texture(int i)
{
    t_pos pos;
    if (!hit_wall(set_pos(&pos, g_rays[i].wall_hit.x + 1, g_rays[i].wall_hit.y)))
        return N_WE;
    else if (!hit_wall(set_pos(&pos, g_rays[i].wall_hit.x - 1, g_rays[i].wall_hit.y)))
        return N_EA;
    else if (!hit_wall(set_pos(&pos, g_rays[i].wall_hit.x, g_rays[i].wall_hit.y + 1)))
        return N_NO;
    else if (!hit_wall(set_pos(&pos, g_rays[i].wall_hit.x, g_rays[i].wall_hit.y - 1)))
        return N_SO;
    
    return 0;
}