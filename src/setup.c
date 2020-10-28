#include "../include/cub3d.h"

void    init(void)
{
    g_game.m_ptr = mlx_init();
    if (!g_game.m_ptr)
    {
        write(1, "Error\nfaild to init mlx", 24);
        free(g_rays);
        exit(1);
    }
    g_game.w_ptr = mlx_new_window(g_game.m_ptr, g_game.win_w, g_game.win_h, "Cub3d");
    if (!g_game.w_ptr)
    {
        write(1, "Error\nfaild to init windows", 28);
        free(g_rays);
        exit(1);
    }
    g_img.img = mlx_new_image(g_game.m_ptr, g_game.win_w,  g_game.win_h);
    if (!g_img.img)
        exit_error("Error\nfaild to init image");
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp, &g_img.length, &g_img.e);
    if (!g_img.addr)
        exit_error("Error\nfaild to init image");
}

int exit_game()
{
	mlx_clear_window(g_game.m_ptr, g_game.w_ptr);
    mlx_destroy_window(g_game.m_ptr, g_game.w_ptr);
    free_map();
    free_paths();
    free(g_rays);
	exit(0);
	return (0);
}

void exit_error(char *s)
{
    write(1, s, ft_strlen(s));
	mlx_clear_window(g_game.m_ptr, g_game.w_ptr);
    mlx_destroy_window(g_game.m_ptr, g_game.w_ptr);
    free_map();
    free_paths();
    free(g_rays);
	exit(1);
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
    sp_pos();
    if (!(g_rays = malloc(sizeof(t_ray) * g_game.win_w)))
    {
        write(1, "Error\nallocation fails at rays", 31);
        exit(1);
    }
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
    sprites();
}

void    update()
{
   move_player();
//    printf("Move player done\n");
   cast_all_rays();
//    printf("cast all rays done\n");
   update_sp_d();
//    printf("update sp distance done\n");
}

int    main_loop()
{
    clear_image();
    update();
    render();
    mlx_put_image_to_window(g_game.m_ptr, g_game.w_ptr, g_img.img, 0, 0);
    
    return 0;
}