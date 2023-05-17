/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: project_isometric.c
*/

#include <lapin.h>
#include "stu_surface.h"

t_bunny_position project_isometric(int x, int y, int z, int coef)
{
    t_bunny_position w;

    w.x = ((0.75 * x) - (0.75 * y)) * coef;
    w.y = (- z + (0.25 * x) + (0.25 * y)) * coef;
    return w;
}
