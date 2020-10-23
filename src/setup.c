#include "../include/cub3d.h"

void    init(void)
{
    g_game.m_ptr = mlx_init();
    if (!g_game.m_ptr)
        write_exit("Error\nfaild to init mlx");
    g_game.w_ptr = mlx_new_window(g_game.m_ptr, g_game.win_w, g_game.win_h, "Cub3d");
    if (!g_game.w_ptr)
        write_exit("Error\nfaild to init windows");
    g_img.img = mlx_new_image(g_game.m_ptr, g_game.win_w,  g_game.win_h);
    if (!g_img.img)
        write_exit("Error\nfaild to init image");
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp, &g_img.length, &g_img.e);
    if (!g_img.addr)
        write_exit("Error\nfaild to init image");
}

int exit_game()
{
	mlx_clear_window(g_game.m_ptr, g_game.w_ptr);
    mlx_destroy_window(g_game.m_ptr, g_game.w_ptr);
	exit(0);
	return (0);
}

void    clear_image()
{
    t_rec r;

    r.pos.x = 0;
    r.pos.y = 0;
    r.size.x = g_game.win_w;
    r.size.y = g_game.win_h;
    r.color = 0x00FFFFFF;
    draw_rect(r);
}

void    process_input(void)
{
    mlx_hook(g_game.w_ptr, EVENT_KEYDOWN, 0, key_down, (void* )0);
    mlx_hook(g_game.w_ptr, EVENT_KEYUP, 0, key_up, (void* )0);
    mlx_hook(g_game.w_ptr, EVENT_EXIT, 0, exit_game, (void* )0);
}

void    setup()
{
    set_text();
    
    if (!(g_rays = malloc(sizeof(t_ray) * g_game.win_w)))
        write_exit("Error\nallocation fails at rays");
    
    g_player.turn_direction = 0;
    g_player.walk_direction = 0;
    init();
    process_input();
    load_texture();
}

void    render()
{
    render_wall();
    render_map();
    render_rays();
    render_player();
    //update_sp_d();
    //sprites();
}

void    update()
{
    move_player();
    cast_all_rays();
}

int    main_loop()
{
    // t_line l;

    // l.d = 50;
    // l.alpha = M_PI / 2;
    // l.pos.x = 500;
    // l.pos.y = 300;
    // l.color = 0x00bb2205;

    // draw_line(l);

    clear_image();
    update();
    render();
    // // if (game->save)
    // //     screanshot(game);
    mlx_put_image_to_window(g_game.m_ptr, g_game.w_ptr, g_img.img, 0, 0);
    
    return 0;
}