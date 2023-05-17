/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: stu_surface.h
*/

#include <lapin.h>
#include "struct.h"

#ifndef STU_SURFACE_H_
#define STU_SURFACE_H_

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);
void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);
float get_ratio(int a, int b, int x);
int get_value(int a, int b, float ratio);
unsigned int mk_colour(unsigned char r,
                       unsigned char g,
                       unsigned char b,
                       unsigned char a);
void put_pixel(t_bunny_pixelarray *pxa,
               t_bunny_position *pos,
               unsigned int color);
t_bunny_position project_paralell(int x, int y, int z, int coef);
t_bunny_position project_isometric(int x, int y, int z, int coef);

void surface(struct surface *opt);
void relief(struct surface *opt, const int *z);

#endif // STU_SURFACE_H_
