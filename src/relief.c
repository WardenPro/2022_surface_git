/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: relief.c
*/

#include <lapin.h>
#include "stu_surface.h"
#include "struct.h"
#include <stdio.h>

void relief(struct surface *opt, const int *z)
{
    t_bunny_position position1;
    t_bunny_position position2;
    t_bunny_position position3;
    t_bunny_position position4;
    int height;
    int width;
    int cube;
    int x;
    int y;
    int i;
    int nb;
    nb = 0;
    y = 0;
    i = 0;
    width = opt->width;
    height = opt->height;
    while (height >= 0) {
        x = 0;
        nb += 1;
        cube = opt->width;
        while (cube > 0) {
            nb += 1;
            if (opt->paralell == 1 && opt->isometric != 1) {
                position1 = project_paralell(x, y, z[i], opt->coef);
                position2 = project_paralell(x + 1, y, z[i + 1], opt->coef);
                position3 = project_paralell(x, y, 0, opt->coef);
                position4 = project_paralell(x + 1, y, 0, opt->coef);
            }  else if (opt->isometric == 1 && opt->paralell != 1) {
                position1 = project_isometric(x, y, z[i], opt->coef);
                position2 = project_isometric(x + 1, y, z[i + 1], opt->coef);
                position3 = project_isometric(x, y, 0, opt->coef);
                position4 = project_isometric(x + 1, y, 0, opt->coef);
            } else {
                return;
            }
            position1.x += opt->start_point.x;
            position1.y += opt->start_point.y;
            position2.x += opt->start_point.x;
            position2.y += opt->start_point.y;
            position3.x += opt->start_point.x;
            position3.y += opt->start_point.y;
            position4.x += opt->start_point.x;
            position4.y += opt->start_point.y;
            stu_draw_line(opt->px, &position1, &position2, BLUE);
            stu_draw_line(opt->px, &position1, &position3, RED);
            stu_draw_line(opt->px, &position2, &position4, RED);
            x += 1;
            i += 1;
            cube -= 1;
        }
        y += 1;
        height -= 1;
    }
    x = 0;
    i = 0;
    while (width >= 0) {
        y = 0;
        cube = opt->height;
        while (cube > 0) {
            if (opt->paralell == 1 && opt->isometric != 1) {
                position1 = project_paralell(x, y, z[i], opt->coef);
                position2 = project_paralell(x, y + 1, z[i + 1], opt->coef);
                position3 = project_paralell(x, y, 0, opt->coef);
                position4 = project_paralell(x, y + 1, 0, opt->coef);
            } else if (opt->isometric == 1 && opt->paralell != 1) {
                position1 = project_isometric(x, y, z[i], opt->coef);
                position2 = project_isometric(x, y + 1, z[i + 1], opt->coef);
                position3 = project_isometric(x, y, 0, opt->coef);
                position4 = project_isometric(x, y + 1, 0, opt->coef);
            } else {
                return;
            }
            position1.x += opt->start_point.x;
            position1.y += opt->start_point.y;
            position2.x += opt->start_point.x;
            position2.y += opt->start_point.y;
            position3.x += opt->start_point.x;
            position3.y += opt->start_point.y;
            position4.x += opt->start_point.x;
            position4.y += opt->start_point.y;
            stu_draw_line(opt->px, &position1, &position2, BLUE);
            stu_draw_line(opt->px, &position1, &position3, RED);
            stu_draw_line(opt->px, &position2, &position4, RED);
            y += 1;
            i += 1;
            cube -= 1;
        }
        x += 1;
        width -= 1;
    }
}
