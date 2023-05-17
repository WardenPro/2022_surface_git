/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: main.c
*/

#include <lapin.h>
#include <unistd.h>
#include <stdlib.h>
#include "stu_surface.h"
#include "struct.h"

const int z[] = {2, 1, 1, 1, 1, 1,
                 1, 1, 1, 1, 1, 1,
                 1, 1, 1, 1, 1, 1,
                 1, 1, 1, 1, 1, 1,
                 1, 1, 1, 1, 1, 1};

int main(void)
{
    t_bunny_window *win;
    t_bunny_position origin;
    struct surface opt;

    opt.start_point.x = 300;
    opt.start_point.y = 300;
    opt.coef = 50;
    opt.height = 4;
    opt.width = 5;
    opt.paralell = 1;
    opt.isometric = 0;
    win = bunny_start(800, 600, false,
                      "fl: surface");
    opt.px = bunny_new_pixelarray(800, 600);
    origin.x = 0;
    origin.y = 0;
    clear_pixelarray(opt.px, BLACK);
    surface(&opt);
    relief(&opt, z);
    bunny_blit(&win->buffer, &opt.px->clipable, &origin);
    bunny_display(win);
    usleep(1e8);
    bunny_stop(win);
    return (EXIT_SUCCESS);
}
