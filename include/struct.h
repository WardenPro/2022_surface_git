/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: struct.h
*/

#include <lapin.h>

#ifndef STRUCT_H_
#define STRUCT_H_

struct surface {
    t_bunny_pixelarray *px;
    t_bunny_position start_point;
    int height;
    int width;
    int coef;
    int paralell;
    int isometric;
};

#endif // STRUCT_H_
