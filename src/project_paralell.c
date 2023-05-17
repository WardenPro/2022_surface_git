/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: project_paralell.c
*/

#include <lapin.h>
#include "stu_surface.h"
#include <stdio.h>

t_bunny_position project_paralell(int x, int y, int z, int coef)
{
    t_bunny_position w;

    w.x = (x - (0.5 * y)) * coef;
    w.y = (- z + (0.5 * y)) * coef;
    return w;
}
