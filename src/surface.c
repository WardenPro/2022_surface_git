/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: surface.c
*/

#include <lapin.h>
#include "stu_surface.h"
#include "struct.h"

void surface(struct surface *opt)
{
    t_bunny_position position1;
    t_bunny_position position2;
    int height;
    int width;
    int cube;
    int x;
    int y;

    y = 0;
    width = opt->width;
    height = opt->height;
    while (height >= 0) {
        x = 0;
        cube = opt->width;
        while (cube > 0) {
            if (opt->paralell == 1 && opt->isometric != 1) {
                position1 = project_paralell(x, y, 0, opt->coef);
                position2 = project_paralell(x + 1, y, 0, opt->coef);
            }  else if (opt->isometric == 1 && opt->paralell != 1) {
                position1 = project_isometric(x, y, 0, opt->coef);
                position2 = project_isometric(x + 1, y, 0, opt->coef);
            } else {
                return;
            }
            position1.x += opt->start_point.x;
            position1.y += opt->start_point.y;
            position2.x += opt->start_point.x;
            position2.y += opt->start_point.y;
            stu_draw_line(opt->px, &position1, &position2, GREEN);
            x += 1;
            cube -= 1;
        }
        y += 1;
        height -= 1;
    }
    x = 0;
    while (width >= 0) {
        y = 0;
        cube = opt->height;
        while (cube > 0) {
            if (opt->paralell == 1 && opt->isometric != 1) {
                position1 = project_paralell(x, y, 0, opt->coef);
                position2 = project_paralell(x, y + 1, 0, opt->coef);
            } else if (opt->isometric == 1 && opt->paralell != 1) {
                position1 = project_isometric(x, y, 0, opt->coef);
                position2 = project_isometric(x, y + 1, 0, opt->coef);
            } else {
                return;
            }
            position1.x += opt->start_point.x;
            position1.y += opt->start_point.y;
            position2.x += opt->start_point.x;
            position2.y += opt->start_point.y;
            stu_draw_line(opt->px, &position1, &position2, GREEN);
            y += 1;
            cube -= 1;
        }
        x += 1;
        width -= 1;
    }
}
