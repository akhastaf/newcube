// #include "../include/cub3d.h"


// void    cast_all_rays()
// {
//     int     i;
//     float   ray_angle;

//     i = 0;
//     ray_angle = g_player.rotation_angle - (FOV / 2);
//     while (i < g_game.win_w)
//     {
//         g_rays[i].angle = ray_angle;
//         cast_ray(i);
//         ray_angle += FOV / g_game.win_w;
//         i++;
//     }
    
// }

// void    render_rays()
// {
//     int i;
//     t_line ray;

//     ray.color = 0xFF0000;
//     i = 0;
//     while (i < g_game.win_w)
//     {
//         copy_pos(&(ray.pos), g_player.pos);
//         ray.pos.x *= SCALE;
//         ray.pos.y *= SCALE;
//         ray.d = g_rays[i].dist * SCALE;
//         ray.alpha = g_rays[i].angle;
//         if (ray.pos.x <= g_game.win_w && ray.pos.y <= g_game.win_h)
//             draw_line(ray);
//         i++;
//     }
// }

// void cast_ray(int id)
// {
//     float xstep;
//     float ystep;
//     float xintercept; // coordinate of the first intersection
//     float yintercept;
//     t_pos next_horz;
//     int horz_hit = 0;
//     float horz_wall_hitx = 0;
//     float horz_wall_hity = 0;
//     int horz_wall_content = 0;
//     float horz_distance;
//     float vert_distance;
    
//     // printf("cast ray");
//     g_rays[id].angle = normalize_angle(g_rays[id].angle);
    
//     int facing_down = ((g_rays[id].angle > 0 && g_rays[id].angle < M_PI)? 1 : 0);
//     int facing_up = !facing_down;
    
//     int facing_right = ((g_rays[id].angle < M_PI * 0.5 || g_rays[id].angle > 1.5 * M_PI) ? 1 : 0);    
//     int facing_left = !facing_right;
    
//     /////////////////////////////
//     // horizontal intersection //
//     ////////////////////////////
    
//     ystep = TILE_SIZE;
//     ystep *= (facing_down ? 1 : -1);
    
//     xstep = ystep / tan(g_rays[id].angle);
//    // xstep *= ((facing_right && xstep < 0) ? -1 : 1);
//    // xstep *= ((facing_left && xstep > 0) ? -1 : 1);
    
    
//     yintercept = floor(g_player.pos.y / TILE_SIZE) * TILE_SIZE;
//     yintercept += (facing_down ? TILE_SIZE : 0);
//     yintercept += (facing_up ? -1 : 0); // make it part of the bloc above the line 
//     xintercept = g_player.pos.x + ((yintercept - g_player.pos.y) / tan(g_rays[id].angle));
    
//     next_horz.x = xintercept;
//     next_horz.y = yintercept;
    
//     while ((next_horz.x > 0 && next_horz.x < g_game.win_w) && (next_horz.y > 0 && next_horz.y < g_game.win_h))
//     {
//         if (hit_wall(next_horz))
//         {
//             horz_hit = 1;
//             horz_wall_hitx = next_horz.x;
//             horz_wall_hity = next_horz.y;
//             horz_wall_content = 1;//map[(int)floor(next_horzy / TILE_SIZE)][(int)floor(next_horzx / TILE_SIZE)];
//             break;
//         }
//         else
//         {
//             next_horz.x += xstep;
//             next_horz.y += ystep;
//         }
//     }

//     ///////////////////////////////////////////////
//     //////////// vertical intersection  ///////////
//     ///////////////////////////////////////////////

//     t_pos next_vert;
//     int vert_hit = 0;
//     float vert_wall_hitx = 0;
//     float vert_wall_hity = 0;
//     int vert_wall_content = 0;
    
//     xstep = TILE_SIZE;
//     xstep *= (facing_left ? -1 : 1);
    
//     ystep = xstep * tan(g_rays[id].angle);
//     //ystep *= ((facing_up && ystep > 0) ? -1 : 1);
//    // ystep *= ((facing_down && ystep < 0) ? -1 : 1);
    
    
//     xintercept = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
//     xintercept += (facing_right ? TILE_SIZE : 0);
//     xintercept += (facing_left ? -1 : 0);
//     yintercept = g_player.pos.y + ((xintercept - g_player.pos.x) * tan(g_rays[id].angle));
    
//     next_vert.x = xintercept;
//     next_vert.y = yintercept;
    
//     while ((next_vert.x > 0 && next_vert.x < g_game.win_w) && (next_vert.y > 0 && next_vert.y < g_game.win_h))
//     {
//         if (hit_wall(next_vert))
//         {
//             vert_hit = 1;
//             vert_wall_hitx = next_vert.x;
//             vert_wall_hity = next_vert.y;
//             vert_wall_content = 1;//map[(int)floor(next_verty / TILE_SIZE)][(int)floor(next_vertx / TILE_SIZE)];
//             break;
//         }
//         else
//         {
//             next_vert.x += xstep;
//             next_vert.y += ystep;
//         }
//     }
//     horz_distance = horz_hit ? distance(g_player.pos.x, g_player.pos.y, horz_wall_hitx, horz_wall_hity) : MAX_INT;
//     vert_distance = vert_hit ? distance(g_player.pos.x, g_player.pos.y, vert_wall_hitx, vert_wall_hity) : MAX_INT;
//     if (vert_distance < horz_distance)
//     {
//         g_rays[id].dist = vert_distance;
//         g_rays[id].wall_hit.x = vert_wall_hitx;
//         g_rays[id].wall_hit.y = vert_wall_hity;
//         g_rays[id].vert_hit = 1;
//     }
//     else
//     {
//         g_rays[id].dist = horz_distance;
//         g_rays[id].wall_hit.x = horz_wall_hitx;
//         g_rays[id].wall_hit.y = horz_wall_hity;
//         g_rays[id].vert_hit = 0;
//     }
//     g_rays[id].angle = g_rays[id].angle;
//     g_rays[id].ray_d = facing_down;
//     g_rays[id].ray_up = facing_up;
//     g_rays[id].ray_r = facing_right;
//     g_rays[id].ray_l = facing_left;
// }
